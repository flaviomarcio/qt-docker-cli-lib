#include "qt-docker-obj-port.h"

namespace QtDockerCli {

Port::Port(QObject *parent):Object{parent}{

}

Port::Protocol Port::protocol() const
{
    return _protocol;
}

void Port::setProtocol(Protocol newProtocol)
{
    if (_protocol == newProtocol)
        return;
    _protocol = newProtocol;
    emit protocolChanged();
}

void Port::resetProtocol()
{
    setProtocol({}); // TODO: Adapt to use your actual default value
}

Port::PublishMode Port::publishMode() const
{
    return _publishMode;
}

void Port::setPublishMode(PublishMode newPublishMode)
{
    if (_publishMode == newPublishMode)
        return;
    _publishMode = newPublishMode;
    emit publishModeChanged();
}

void Port::resetPublishMode()
{
    setPublishMode({}); // TODO: Adapt to use your actual default value
}

int Port::targetPort() const
{
    return _targetPort;
}

void Port::setTargetPort(int newTargetPort)
{
    if (_targetPort == newTargetPort)
        return;
    _targetPort = newTargetPort;
    emit targetPortChanged();
}

void Port::resetTargetPort()
{
    setTargetPort({}); // TODO: Adapt to use your actual default value
}

int Port::publishedPort() const
{
    return _publishedPort;
}

void Port::setPublishedPort(int newPublishedPort)
{
    if (_publishedPort == newPublishedPort)
        return;
    _publishedPort = newPublishedPort;
    emit publishedPortChanged();
}

void Port::resetPublishedPort()
{
    setPublishedPort({}); // TODO: Adapt to use your actual default value
}

}
