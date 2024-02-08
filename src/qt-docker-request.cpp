#include "qt-docker-request.h"
#include "../3rdparty/qstm/src/qstm_meta_enum.h"
#include <QLocalSocket>
#include <QMutex>
#include <QThread>
#include <QDebug>
#include <QJsonDocument>

namespace QtDockerCli {

static const auto __fault_is_running="Socket running...";

typedef std::function<void()> MethodSocketConnected;

class RequestPvt: public QObject{
public:
    Request *parent;
    QLocalSocket* socket=nullptr;
    QStm::MetaEnum<Request::Method> method=Request::Method::GET;
    QString path;
    QVariant args;
    QMutex lockStart;
    QMutex *lock=nullptr;
    QString serverName="/var/run/docker.sock";
    QVariantHash responseHeaders;
    int responseStatus=-1;
    QByteArray responseReason;
    QByteArray responseBody;
    Response response;
    explicit RequestPvt(Request *parent=nullptr):QObject{parent}, parent{parent}, response{parent}{
    }

    ~RequestPvt(){
        this->clear();
    }

    void clear(){
        sckClose();
        this->requestClear();
        this->responseClear();
    }

    void requestClear(){
        sckClose();
        this->serverName="/var/run/docker.sock";
        this->method=Request::GET;
        this->args.clear();
    }

    void responseClear(){
        this->responseHeaders.clear();
        this->responseStatus=-1;
        this->responseReason.clear();
        this->responseBody.clear();
    }

    void mWait(){
        lockStart.lock();
        if(lock==nullptr)
            return;
        lockStart.unlock();
        while(lock!=nullptr)
            QThread::msleep(1);
    }

    bool mLock(){
        QMutexLocker locker(&lockStart);
        if(lock!=nullptr)
            return false;

        auto lock=new QMutex();
        lock->tryLock();
        this->lock=lock;
        return true;
    }

    void mUnlock(){
        QMutexLocker locker(&lockStart);
        if(this->lock==nullptr)
            return;
        this->lock->unlock();
        this->lock=nullptr;
        emit this->parent->finished();
    }

    QLocalSocket *sckOpen(){
        if(!mLock())
            return nullptr;
        sckClose();
        QMutexLocker locker(&lockStart);

        this->responseClear();
        QLocalSocket* socket = new QLocalSocket(this);

        // QObject::connect(socket, &QLocalSocket::connected, [=]() {
        //     emit parent->started();
        //     socket->write(args.toUtf8());
        //     socket->flush();
        //     emit parent->sent(args);
        // });

        // QObject::connect(socket, &QLocalSocket::readyRead, [=]() {
        //     responseBody = socket->readAll();
        //     emit this->parent->received(responseBody);
        // });

        // QObject::connect( socket, &QLocalSocket::disconnected, [=](){
        //     sckClose();
        // });

        // QObject::connect(socket, &QLocalSocket::errorOccurred, [=](QLocalSocket::LocalSocketError ) {
        //     sckClose();
        //     emit this->parent->finished();
        // });

        socket->connectToServer( this->serverName, QIODevice::ReadWrite);
        if(!socket->waitForConnected()){
            socket->deleteLater();
            return nullptr;
        }
        return (this->socket=socket);
    }

    void sckClose(){
        mUnlock();
        QMutexLocker locker(&lockStart);
        if(socket==nullptr)
            return;
        auto aux=socket;
        socket=nullptr;
        aux->disconnectFromServer();
        aux->close();
        aux->deleteLater();
    }

    void call(){
        emit this->parent->started();
        auto socket = sckOpen();
        if(socket==nullptr){
            emit parent->fail(__fault_is_running);
        }
        else if (!socket->waitForConnected()){
            emit parent->fail("Failed to connect to Docker socket:"+socket->errorString());
        }
        else{
            static const auto __request=QStringLiteral("%1 %2 HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n");

            // Envie a solicitação para listar os contêineres
            auto requestData = __request.arg(this->method.name(), this->path).toUtf8();
            socket->write(requestData);
            socket->waitForBytesWritten();

            QByteArray responseData;
            while (socket->waitForReadyRead())
                responseData.append(socket->readAll());

            static const auto responseStart="HTTP/";//HTTP/1.1 200 OK\r
            static const auto responseBodyStart=QByteArrayLiteral("25e4\r");
            static const auto responseEnd=QByteArrayLiteral("0\r");

            bool bodyStarted=false;
            auto rows=responseData.split('\n');
            responseData.clear();
            for(auto&v:rows){

                if(v.startsWith(responseStart)){
                    auto values=v.split(' ');
                    this->responseStatus=
                        (values.size()>1)?QVariant(values.value(1).trimmed()).toInt():-1;
                    this->responseReason=
                        (values.size()>2)?values.value(2).trimmed():"";
                    continue;
                }
                else if(v==responseBodyStart){
                    bodyStarted=true;
                    continue;
                }
                else if(v.startsWith(responseEnd)){
                    break;
                }
                else if(v==responseBodyStart){
                    bodyStarted=true;
                    continue;
                }
                else if(bodyStarted){
                    v=v.trimmed();

                    if(v.isEmpty())
                        continue;

                    auto values=v.split(':');
                    if(values.isEmpty())
                        continue;
                    auto key=values.value(0);
                    auto value = (values.size()>1)?values.value(1):"";
                    responseHeaders.insert(key,value);

                    responseData.append(v);
                }
            }

            this->responseBody=responseData;
        }
        sckClose();
        emit this->parent->finished();
    }
};

Response::Response(Request *request):QObject{request}, request{request}
{
}

Response::operator bool() const
{
    return this->isOK();
}

bool Response::isOK()const
{
    auto p=request->p;
    if(p->responseStatus>=200 && p->responseStatus<=299)
        return true;
    return false;
}

QVariantHash &Response::headers() const
{
    auto p=request->p;
    return p->responseHeaders;
}

int &Response::statusCode() const
{
    auto p=request->p;
    return p->responseStatus;
}

QByteArray &Response::reansonPhrase() const
{
    auto p=request->p;
    return p->responseReason;
}

QByteArray &Response::body()const
{
    auto p=request->p;
    return p->responseBody;
}

QVariantMap Response::asMap() const
{
    return this->asVariant().toMap();
}

QVariantHash Response::asHash() const
{
    return this->asVariant().toHash();
}

QVariantList Response::asList() const
{
    auto v=this->asVariant();
    switch (v.typeId()) {
    case QMetaType::QStringList:
    case QMetaType::QVariantList:
        return v.toList();
    default:
        return {};
    }
}

QVariant Response::asVariant() const
{
    auto p=request->p;
    auto v=QJsonDocument::fromJson(p->responseBody).toVariant();
    return v;
}

Request::Request(QObject *parent):QObject{parent}, p{new RequestPvt{this}}
{
}


Request &Request::clear()
{
    p->clear();
    return *this;
}

QString &Request::serverName()const
{
    return p->serverName;
}

Request &Request::serverName(const QString &newServerName)
{
    p->serverName=newServerName;
    return *this;
}

Request::Method Request::method()
{
    return p->method.type();
}

Request &Request::method(const Method &newMethod)
{
    p->method=newMethod;
    return *this;
}

QString &Request::path() const
{
    return p->path;
}

Request &Request::path(const QString &newPath)
{
    p->path=newPath;
    return *this;
}

QVariant &Request::args() const
{
    return p->args;
}

Request &Request::args(const QVariant &newArgs)
{
    p->args=newArgs;
    return *this;
}

Request &Request::call()
{
    p->call();
    return *this;
}

Request &Request::call(const QString &path)
{
    p->path=path;
    p->call();
    return *this;
}

Request &Request::wait()
{
    p->mWait();
    return *this;
}

Response &Request::response()
{
    return p->response;
}

}
