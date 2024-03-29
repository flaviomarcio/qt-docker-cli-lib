#include "qt-docker-obj-container.h"

namespace QtDockerCli {

Container::Container(QObject *parent):Object{parent}{

}

QString Container::id() const
{
    return _id;
}

void Container::setId(const QString &newId)
{
    if (_id == newId)
        return;
    _id = newId;
    emit idChanged();
}

void Container::resetId()
{
    setId({}); 
}

QStringList Container::names() const
{
    return _names;
}

void Container::setNames(const QStringList &newNames)
{
    if (_names == newNames)
        return;
    _names = newNames;
    emit namesChanged();
}

void Container::resetNames()
{
    setNames({}); 
}

QString Container::image() const
{
    return _image;
}

void Container::setImage(const QString &newImage)
{
    if (_image == newImage)
        return;
    _image = newImage;
    emit imageChanged();
}

void Container::resetImage()
{
    setImage({}); 
}

QString Container::imageID() const
{
    return _imageID;
}

void Container::setImageID(const QString &newImageID)
{
    if (_imageID == newImageID)
        return;
    _imageID = newImageID;
    emit imageIDChanged();
}

void Container::resetImageID()
{
    setImageID({}); 
}

QString Container::command() const
{
    return _command;
}

void Container::setCommand(const QString &newCommand)
{
    if (_command == newCommand)
        return;
    _command = newCommand;
    emit commandChanged();
}

void Container::resetCommand()
{
    setCommand({}); 
}

QString Container::created() const
{
    return _created;
}

void Container::setCreated(const QString &newCreated)
{
    if (_created == newCreated)
        return;
    _created = newCreated;
    emit createdChanged();
}

void Container::resetCreated()
{
    setCreated({}); 
}

QVariantList Container::ports() const
{
    return _ports;
}

void Container::setPorts(const QVariantList &newPorts)
{
    if (_ports == newPorts)
        return;
    _ports = newPorts;
    emit portsChanged();
}

void Container::resetPorts()
{
    setPorts({}); 
}

QVariantHash Container::labels() const
{
    return _labels;
}

void Container::setLabels(const QVariantHash &newLabels)
{
    if (_labels == newLabels)
        return;
    _labels = newLabels;
    emit labelsChanged();
}

void Container::resetLabels()
{
    setLabels({}); 
}

QString Container::state() const
{
    return _state;
}

void Container::setState(const QString &newState)
{
    if (_state == newState)
        return;
    _state = newState;
    emit stateChanged();
}

void Container::resetState()
{
    setState({}); 
}

QString Container::status() const
{
    return _status;
}

void Container::setStatus(const QString &newStatus)
{
    if (_status == newStatus)
        return;
    _status = newStatus;
    emit statusChanged();
}

void Container::resetStatus()
{
    setStatus({}); 
}

QVariantHash Container::hostConfig() const
{
    return _hostConfig;
}

void Container::setHostConfig(const QVariantHash &newHostConfig)
{
    if (_hostConfig == newHostConfig)
        return;
    _hostConfig = newHostConfig;
    emit hostConfigChanged();
}

void Container::resetHostConfig()
{
    setHostConfig({}); 
}

QVariantHash Container::networkSettings() const
{
    return _networkSettings;
}

void Container::setNetworkSettings(const QVariantHash &newNetworkSettings)
{
    if (_networkSettings == newNetworkSettings)
        return;
    _networkSettings = newNetworkSettings;
    emit networkSettingsChanged();
}

void Container::resetNetworkSettings()
{
    setNetworkSettings({}); 
}

QVariantList Container::mounts() const
{
    return _mounts;
}

void Container::setMounts(const QVariantList &newMounts)
{
    if (_mounts == newMounts)
        return;
    _mounts = newMounts;
    emit mountsChanged();
}

void Container::resetMounts()
{
    setMounts({}); 
}

}
