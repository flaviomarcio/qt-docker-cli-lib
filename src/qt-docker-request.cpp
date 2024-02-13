#include "qt-docker-request.h"
#include "../3rdparty/qstm/src/qstm_meta_enum.h"
#include <QLocalSocket>
#include <QMutex>
#include <QThread>
#include <QDebug>
#include <QJsonDocument>

namespace QtDockerCli {

static const auto __headers="headers";
static const auto __method="method";
static const auto __hostname="hostName";
static const auto __protocol="protocol";
static const auto __basepath="basePath";
static const auto __path="path";
static const auto __args="args";
static const auto __body="body";
static const auto __uri="uri";

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
    QMutex lockStart;
    Request *parent;
    QStm::MetaEnum<Request::Method> method=Request::Method::Get;
    QVariantHash headers;
    QString socket="/var/run/docker.sock";
    QString protocol;
    QString hostName;
    int port=0;
    QString basePath;
    QString path;
    QVariant args;
    QVariant body;
    QByteArray responseProtocol;
    int responseStatus=-1;
    QVariantHash responseHeaders;
    QByteArray responseReason;
    QByteArray responseBody;
    Response response;
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
        this->method=Request::Get;
        this->protocol.clear();
        this->hostName.clear();
        this->port=0;
        this->basePath.clear();
        this->path.clear();
        this->args.clear();
        this->args.clear();
    }

    void responseClear(){
        this->responseProtocol.clear();
        this->responseStatus=-1;
        this->responseReason.clear();
        this->responseHeaders.clear();
        this->responseBody.clear();
    }

    QUrl url(){
        auto sport=(this->port==0 || this->port==80 || this->port==443)
                         ?""
                         :QStringLiteral(":%1").arg(this->port);
        auto path=QString("%1%2/%3/%4").arg(hostName, sport, basePath, this->path);
        while(path.contains(__path_separador_double))
            path=path.replace(__path_separador_double,__path_separador);
        auto url=QString("%1:%2%3").arg(this->protocol, __path_separador_double, path);
        return QUrl(url);
    }

    void mWait(){
        QMutexLocker locker(&lockStart);
    }

    QLocalSocket *sckOpen(){
        QMutexLocker locker(&lockStart);

        this->responseClear();
        QLocalSocket* socket = new QLocalSocket(this);

        socket->connectToServer( this->socket, QIODevice::ReadWrite);
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

    QStringList responseGetBlock(QList<QByteArray> &lines){
        QStringList __return;
        while(!lines.isEmpty()){
            auto line=lines.takeFirst();
            if(line=="\r")
                break;

            line=line.trimmed();
            if(!line.isEmpty())
                __return.append(line.trimmed());
        }

        return __return;
    }

    void responseReadProtocol(QList<QByteArray> &lines){
        if(lines.isEmpty())
            return;
        auto v=lines.takeFirst();
        static const auto responseStart="HTTP/";//HTTP/1.1 200 OK\r
        if(!v.startsWith(responseStart))
            return;
        auto values=v.split(' ');

        this->responseProtocol=values.value(0).trimmed();

        this->responseStatus=
            (values.size()>1)?QVariant(values.value(1).trimmed()).toInt():-1;
        this->responseReason=
            (values.size()>2)?values.value(2).trimmed():"";
    }

    void responseReadHeaders(QList<QByteArray> &lines){
        if(lines.isEmpty())
            return;

        auto block=responseGetBlock(lines);
        for (auto &v:block) {
            auto values=v.trimmed().split(':');
            if(values.isEmpty())
                continue;
            auto key=values.value(0);
            auto value = (values.size()>1)?values.value(1):"";
            this->responseHeaders.insert(key,value);
        }
    }

    void responseReadBody(QList<QByteArray> &lines){
        if(lines.isEmpty())
            return;
        auto firstLine=lines.takeFirst();
        auto block=responseGetBlock(lines);
        if(block.isEmpty())
            block.append(firstLine);
        for (auto &v:block)
            this->responseBody.append(v.toUtf8());
    }


    void call(){
        this->responseClear();
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
            auto requestData = __request.arg(this->method.name().toUpper(), this->url().toString()).toUtf8();
            socket->write(requestData);
            socket->waitForBytesWritten();

            QByteArray buffer;
            while (socket->waitForReadyRead())
                buffer.append(socket->readAll());
            auto rows=buffer.split('\n');
            buffer.clear();

            this->responseReadProtocol(rows);
            this->responseReadHeaders(rows);
            this->responseReadBody(rows);
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

QVariantHash Request::settings()
{
    QVariantHash __return;
    __return.insert(__method, p->method.name());
    __return.insert(__headers, p->headers);
    __return.insert(__protocol, p->protocol);
    __return.insert(__hostname, p->hostName);
    __return.insert(__basepath, p->basePath);
    __return.insert(__path, p->path);
    __return.insert(__args, p->args);
    __return.insert(__body, p->body);
    __return.insert(__uri, this->url());
    return __return;
}

Request &Request::settings(const QVariant &newSettings)
{
    auto vHash=newSettings.toHash();
    p->protocol=newSettings.toString();
    if(vHash.contains(__method))
        p->method = vHash.value(__method);

    if(vHash.contains(__headers))
        p->headers = vHash.value(__headers).toHash();

    if(vHash.contains(__protocol))
        p->protocol = vHash.value(__protocol).toString();

    if(vHash.contains(__hostname))
        p->hostName = vHash.value(__hostname).toString();

    if(vHash.contains(__basepath))
        p->basePath = vHash.value(__basepath).toString();

    if(vHash.contains(__path))
        p->path = vHash.value(__path).toString();

    if(vHash.contains(__args))
        p->args = vHash.value(__args).toString();

    if(vHash.contains(__body))
        p->body = vHash.value(__body).toString();

    return *this;
}

QUrl Request::url() const
{
    return p->url();
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

int Request::port() const
{
    return p->port;
}

Request &Request::port(const int port)
{
    p->port=port;
    return *this;
}

QString &Request::basePath() const
{
    return p->basePath;
}

Request &Request::basePath(const QString &newBasePath)
{
    p->basePath=newBasePath;
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
