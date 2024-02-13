#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {
class RemoteHost;

//!
//! \brief The RemoteHost class
//!
class QT_DOCKER_CLI_LIB_EXPORT RemoteHost: public Object
{
    Q_OBJECT
    Q_PROPERTY(QString protocol READ protocol WRITE setProtocol RESET resetProtocol NOTIFY protocolChanged FINAL)
    Q_PROPERTY(QString hostName READ hostName WRITE setHostName RESET resetHostName NOTIFY hostNameChanged FINAL)
    Q_PROPERTY(QString basePath READ basePath WRITE setBasePath RESET resetBasePath NOTIFY basePathChanged FINAL)
    Q_PROPERTY(QString userName READ userName WRITE setUserName RESET resetUserName NOTIFY userNameChanged FINAL)
    Q_PROPERTY(QString password READ password WRITE setPassword RESET resetPassword NOTIFY passwordChanged FINAL)
    Q_PROPERTY(int port READ port WRITE setPort RESET resetPort NOTIFY portChanged FINAL)
    Q_PROPERTY(QString socket READ socket WRITE setSocket RESET resetSocket NOTIFY socketChanged FINAL)
public:
    //!
    //! \brief RemoteHost
    //! \param parent
    //!
    Q_INVOKABLE explicit RemoteHost(QObject *parent=nullptr);

    //!
    //! \brief protocol
    //! \return
    //!
    QString protocol() const;
    void setProtocol(const QString &newProtocol);
    void resetProtocol();

    //!
    //! \brief hostName
    //! \return
    //!
    QString hostName() const;
    void setHostName(const QString &newHostName);
    void resetHostName();

    //!
    //! \brief basePath
    //! \return
    //!
    QString basePath() const;
    void setBasePath(const QString &newBasePath);
    void resetBasePath();

    //!
    //! \brief userName
    //! \return
    //!
    QString userName() const;
    void setUserName(const QString &newUserName);
    void resetUserName();

    //!
    //! \brief password
    //! \return
    //!
    QString password() const;
    void setPassword(const QString &newPassword);
    void resetPassword();

    //!
    //! \brief port
    //! \return
    //!
    int port() const;
    void setPort(int newPort);
    void resetPort();

    //!
    //! \brief socket
    //! \return
    //!
    QString socket() const;
    void setSocket(const QString &newSocket);
    void resetSocket();

private:
    QString _protocol;
    QString _hostName;
    QString _basePath;
    QString _userName;
    QString _password;
    int _port=0;
    QString _socket;
signals:
    void protocolChanged();

    void hostNameChanged();

    void basePathChanged();

    void userNameChanged();

    void passwordChanged();

    void portChanged();

    void socketChanged();
};

}
