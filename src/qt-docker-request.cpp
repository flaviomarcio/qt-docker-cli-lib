#include "qt-docker-request.h"
#include <QLocalSocket>
#include <QMutex>
#include <QThread>

namespace QtDockerCli {

static const auto __fault_is_running="Socket running...";

class RequestPvt: public QObject{
public:
    Request *parent;
    QLocalSocket* socket=nullptr;
    QMutex lockStart;
    QMutex *lock=nullptr;
    QString serverName="/var/run/docker.sock";
    QByteArray responseBody;
    explicit RequestPvt(Request *parent=nullptr):QObject{parent}, parent{parent}{
    }

    void clear(){
        sckClose();
        this->serverName="/var/run/docker.sock";
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
        QLocalSocket* socket = new QLocalSocket(this);
        socket->connectToServer( serverName, QIODevice::ReadWrite);
        return socket;
    }

    void sckClose(){
        QMutexLocker locker(&lockStart);
        mUnlock();
        if(socket==nullptr)
            return;
        auto aux=socket;
        socket=nullptr;
        aux->disconnectFromServer();
        aux->close();
        aux->deleteLater();
        emit this->parent->finished();
    }

    void call(const QByteArray &args){
        emit this->parent->started();

        auto socket = sckOpen();
        if(socket==nullptr){
            emit parent->fail(__fault_is_running);
            return;
        }

        QObject::connect(socket, &QLocalSocket::connected, [=]() {
            emit parent->started();
            socket->write(args);
            socket->flush();
            emit parent->sent(args);
        });

        QObject::connect(socket, &QLocalSocket::readyRead, [=]() {
            responseBody = socket->readAll();
            emit this->parent->received(responseBody);
        });

        QObject::connect( socket, &QLocalSocket::disconnected, [=](){
            sckClose();
        });

        QObject::connect(socket, &QLocalSocket::errorOccurred, [=](QLocalSocket::LocalSocketError ) {
            sckClose();
            emit this->parent->finished();
        });
    }
};

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

Request &Request::call(const QByteArray &args)
{
    p->call(args);
    return *this;
}

Request &Request::wait()
{
    p->mWait();
    return *this;
}

QByteArray &Request::responseBody()const
{
    return p->responseBody;
}

}
