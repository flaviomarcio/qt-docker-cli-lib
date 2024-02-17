#include "qt-docker-obj-server.h"

namespace QtDockerCli {

Server::Server(QObject *parent):Object{parent}{

}

QString Server::name() const
{
    return _name;
}

void Server::setName(const QString &newName)
{
    if (_name == newName)
        return;
    _name = newName;
    emit nameChanged();
}

void Server::resetName()
{
    setName({});
}

}
