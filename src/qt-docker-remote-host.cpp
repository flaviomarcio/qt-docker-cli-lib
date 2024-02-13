#include "qt-docker-remote-host.h"

namespace QtDockerCli {

static const auto __protocol_http="http";
static const auto __docker_socket="/var/run/docker.sock";
static const auto __localhost="/var/run/docker.sock";

RemoteHost::RemoteHost(QObject *parent):Object{parent}
{
}

QString RemoteHost::protocol() const
{
    if(_protocol.trimmed().isEmpty())
        return __protocol_http;
    return _protocol;
}

void RemoteHost::setProtocol(const QString &newProtocol)
{
    if (_protocol == newProtocol)
        return;
    _protocol = newProtocol;
    emit protocolChanged();
}

void RemoteHost::resetProtocol()
{
    setProtocol({});
}

QString RemoteHost::hostName() const
{
    if(this->_hostName.isEmpty())
        return __localhost;
    return _hostName;
}

void RemoteHost::setHostName(const QString &newHostName)
{
    if (_hostName == newHostName)
        return;
    _hostName = newHostName;
    emit hostNameChanged();
}

void RemoteHost::resetHostName()
{
    setHostName({});
}

QString RemoteHost::basePath() const
{
    return _basePath;
}

void RemoteHost::setBasePath(const QString &newBasePath)
{
    if (_basePath == newBasePath)
        return;
    _basePath = newBasePath;
    emit basePathChanged();
}

void RemoteHost::resetBasePath()
{
    setBasePath({});
}

QString RemoteHost::userName() const
{
    return _userName;
}

void RemoteHost::setUserName(const QString &newUserName)
{
    if (_userName == newUserName)
        return;
    _userName = newUserName;
    emit userNameChanged();
}

void RemoteHost::resetUserName()
{
    setUserName({});
}

QString RemoteHost::password() const
{
    return _password;
}

void RemoteHost::setPassword(const QString &newPassword)
{
    if (_password == newPassword)
        return;
    _password = newPassword;
    emit passwordChanged();
}

void RemoteHost::resetPassword()
{
    setPassword({});
}

int RemoteHost::port() const
{
    if(_port<0)
        return 0;
    return _port;
}

void RemoteHost::setPort(int newPort)
{
    if (_port == newPort)
        return;
    _port = newPort;
    emit portChanged();
}

void RemoteHost::resetPort()
{
    setPort(0);
}

QString RemoteHost::socket() const
{
    if(_socket.trimmed().isEmpty())
        return __docker_socket;
    return _socket;
}

void RemoteHost::setSocket(const QString &newSocket)
{
    if (_socket == newSocket)
        return;
    _socket = newSocket;
    emit socketChanged();
}

void RemoteHost::resetSocket()
{
    setSocket({});
}

}
