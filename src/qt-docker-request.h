#pragma once

#include <QObject>
#include "qt-docker-global.h"

namespace QtDockerCli {
class RequestPvt;
class Request;

class QT_DOCKER_CLI_LIB_EXPORT Response: public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Response(Request *parent=nullptr);

    operator bool() const;

    //!
    //! \brief isOK
    //! \return
    //!
    bool isOK() const;

    //!
    //! \brief headers
    //! \return
    //!
    QVariantHash &headers() const;

    //!
    //! \brief statusCode
    //! \return
    //!
    int &statusCode() const;

    //!
    //! \brief reansonPhrase
    //! \return
    //!
    QByteArray &reansonPhrase() const;

    //!
    //! \brief body
    //! \return
    //!
    QByteArray &body() const;

    //!
    //! \brief asMap
    //! \return
    //!
    QVariantMap asMap() const;

    //!
    //! \brief asHash
    //! \return
    //!
    QVariantHash asHash() const;

    //!
    //! \brief asList
    //! \return
    //!
    QVariantList asList() const;

    //!
    //! \brief asVariant
    //! \return
    //!
    QVariant asVariant() const;
private:
    Request *request=nullptr;
};


//!
//! \brief The Request class
//!
class QT_DOCKER_CLI_LIB_EXPORT Request: public QObject
{
    Q_OBJECT
    friend class Response;
    friend class RequestPvt;
public:
    enum Method{
        Head,Get,Post,Put,Delete
    };

    Q_ENUM(Method)

    //!
    //! \brief Request
    //! \param parent
    //!
    Q_INVOKABLE explicit Request(QObject *parent=nullptr);

    Request &UnSetProtocol();
    Request &HTTP();
    Request &HTTPS();
    Request &TCP();
    Request &UDP();

    Request &HEAD();
    Request &GET();
    Request &POST();
    Request &PUT();
    Request &DELETE();

    //!
    //! \brief clear
    //! \return
    //!
    Request &clear();

    //!
    //! \brief url
    //! \return
    //!
    QUrl &url()const;

    //!
    //! \brief protocol
    //! \return
    //!
    QString &protocol() const;
    Request &protocol(const QString &newProtocol);

    //!
    //! \brief hostName
    //! \return
    //!
    QString &hostName() const;
    Request &hostName(const QString &newServerName);

    //!
    //! \brief method
    //! \return
    //!
    Method method();
    Request &method(const Method &newMethod);

    //!
    //! \brief path
    //! \return
    //!
    QString &path() const;
    Request &path(const QString &newPath);

    //!
    //! \brief args
    //! \return
    //!
    QVariant &args() const;
    Request &args(const QVariant &newArgs);

    //!
    //! \brief call
    //! \param args
    //! \return
    //!
    Request &call();
    Request &call(const QString &path);

    //!
    //! \brief wait
    //! \return
    //!
    Request &wait();

    //!
    //! \brief response
    //! \return
    //!
    Response &response();

private:
    RequestPvt *p=nullptr;
signals:
    void started();
    void connected();
    void sent(QString args);
    void received(QByteArray body);
    void fail(QString message);
    void finished();
};

}
