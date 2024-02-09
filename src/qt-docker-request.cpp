#include "qt-docker-request.h"
#include "../3rdparty/qstm/src/qstm_meta_enum.h"
#include <QLocalSocket>
#include <QMutex>
#include <QThread>
#include <QDebug>
#include <QJsonDocument>

namespace QtDockerCli {

static const auto __protocol_http="http";
static const auto __protocol_https="https";
static const auto __protocol_tcp="tcp";
static const auto __protocol_udp="udp";
static const auto __fault_is_running="Socket running...";
static const auto __path_separador="/";
static const auto __path_separador_double="//";

typedef std::function<void()> MethodSocketConnected;

class RequestPvt: public QObject{
public:
    Request *parent;
    QStm::MetaEnum<Request::Method> method=Request::Method::Get;
    QString protocol;
    QString path;
    QVariant args;
    QMutex lockStart;
    QString hostName="/var/run/docker.sock";
    QVariantHash responseHeaders;
    int responseStatus=-1;
    QByteArray responseReason;
    QByteArray responseBody;
    Response response;
    QUrl uri;
    explicit RequestPvt(Request *parent=nullptr):QObject{parent}, parent{parent}, response{parent}{
    }

    ~RequestPvt(){
        this->clear();
    }

    void clear(){
        this->requestClear();
        this->responseClear();
    }

    void requestClear(){
        this->hostName="/var/run/docker.sock";
        this->protocol.clear();
        this->hostName.clear();
        this->parent->clear();
        this->args.clear();
        this->method=Request::Get;
        this->args.clear();
    }

    void responseClear(){
        this->responseHeaders.clear();
        this->responseStatus=-1;
        this->responseReason.clear();
        this->responseBody.clear();
    }

    void mWait(){
        QMutexLocker locker(&lockStart);
    }

    QLocalSocket *sckOpen(){
        QMutexLocker locker(&lockStart);

        this->responseClear();
        QLocalSocket* socket = new QLocalSocket(this);

        socket->connectToServer( this->hostName, QIODevice::ReadWrite);
        if(!socket->waitForConnected()){
            socket->deleteLater();
            return nullptr;
        }
        return socket;
    }

    void sckClose(QLocalSocket* socket){
        if(socket==nullptr)
            return;
        if(socket->state()==QLocalSocket::ConnectedState){
            socket->disconnectFromServer();
            socket->waitForDisconnected();
        }
        if(socket->isOpen())
            socket->close();
        delete socket;
    }

    void call(){
        emit this->parent->started();
        auto socket = sckOpen();
        QMutexLocker locker(&lockStart);
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
            static const auto responseContinue=QByteArrayLiteral("\r");
            static const auto responseEnd=QByteArrayLiteral("0\r");

            bool bodyStarted=false;
            auto rows=responseData.split('\n');
            responseData.clear();
            for(auto&v:rows){

                if(v==responseContinue)
                    continue;
                else if(v.startsWith(responseStart)){
                    auto values=v.split(' ');
                    this->responseStatus=
                        (values.size()>1)?QVariant(values.value(1).trimmed()).toInt():-1;
                    this->responseReason=
                        (values.size()>2)?values.value(2).trimmed():"";
                }
                else if(v==responseBodyStart){
                    bodyStarted=true;
                }
                else if(v==responseEnd){
                    continue;
                }
                else if(!bodyStarted){
                    auto values=v.trimmed().split(':');
                    if(values.isEmpty())
                        continue;
                    auto key=values.value(0);
                    auto value = (values.size()>1)?values.value(1):"";
                    responseHeaders.insert(key,value);
                }
                else {
                    responseData.append(v);
                }
            }

            this->responseBody=responseData;
        }
        sckClose(socket);
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

Request &Request::UnSetProtocol()
{
    return this->protocol({});
}

Request &Request::HTTP()
{
    return this->protocol(__protocol_http);
}

Request &Request::HTTPS()
{
    return this->protocol(__protocol_https);
}

Request &Request::TCP()
{
    return this->protocol(__protocol_tcp);
}

Request &Request::UDP()
{
    return this->protocol(__protocol_udp);
}

Request &Request::HEAD()
{
    return this->method(Head);
}

Request &Request::GET()
{
    return this->method(Get);
}

Request &Request::POST()
{
    return this->method(Post);
}

Request &Request::PUT()
{
    return this->method(Put);
}

Request &Request::DELETE()
{
    return this->method(Delete);
}

Request &Request::clear()
{
    p->clear();
    return *this;
}

QUrl &Request::url() const
{
    auto path=QString("%1%2").arg(this->hostName(), this->path());
    while(path.contains(__path_separador_double))
        path=path.replace(__path_separador_double,__path_separador);
    auto url=QString("%1:%2%3").arg(this->protocol(), __path_separador_double, path);
    return p->uri=QUrl(url);
}

QString &Request::protocol() const
{
    return p->protocol;
}

Request &Request::protocol(const QString &newProtocol)
{
    p->protocol=newProtocol.trimmed().toLower();
    return *this;
}

QString &Request::hostName()const
{
    return p->hostName;
}

Request &Request::hostName(const QString &newServerName)
{
    p->hostName=newServerName;
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
