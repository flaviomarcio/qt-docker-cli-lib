#include "qt-docker-obj-volume.h"

namespace QtDockerCli {

Volume::Volume(QObject *parent):Object{parent}{

}

QDateTime Volume::createdAt() const
{
    return _createdAt;
}

void Volume::setCreatedAt(const QDateTime &newCreatedAt)
{
    if (_createdAt == newCreatedAt)
        return;
    _createdAt = newCreatedAt;
    emit createdAtChanged();
}

void Volume::resetCreatedAt()
{
    setCreatedAt({}); // TODO: Adapt to use your actual default value
}

QString Volume::driver() const
{
    return _driver;
}

void Volume::setDriver(const QString &newDriver)
{
    if (_driver == newDriver)
        return;
    _driver = newDriver;
    emit driverChanged();
}

void Volume::resetDriver()
{
    setDriver({}); // TODO: Adapt to use your actual default value
}

QVariantHash Volume::labels() const
{
    return _labels;
}

void Volume::setLabels(const QVariantHash &newLabels)
{
    _labels = newLabels;
    emit labelsChanged();
}

void Volume::resetLabels()
{
    setLabels({}); // TODO: Adapt to use your actual default value
}

QString Volume::mountPoint() const
{
    return _mountPoint;
}

void Volume::setMountPoint(const QString &newMountPoint)
{
    if (_mountPoint == newMountPoint)
        return;
    _mountPoint = newMountPoint;
    emit mountPointChanged();
}

void Volume::resetMountPoint()
{
    setMountPoint({}); // TODO: Adapt to use your actual default value
}

QString Volume::name() const
{
    return _name;
}

void Volume::setName(const QString &newName)
{
    if (_name == newName)
        return;
    _name = newName;
    emit nameChanged();
}

void Volume::resetName()
{
    setName({}); // TODO: Adapt to use your actual default value
}

QVariantHash Volume::options() const
{
    return _options;
}

void Volume::setOptions(const QVariantHash &newOptions)
{
    _options = newOptions;
    emit optionsChanged();
}

void Volume::resetOptions()
{
    setOptions({}); // TODO: Adapt to use your actual default value
}

QString Volume::scope() const
{
    return _scope;
}

void Volume::setScope(const QString &newScope)
{
    if (_scope == newScope)
        return;
    _scope = newScope;
    emit scopeChanged();
}

void Volume::resetScope()
{
    setScope({}); // TODO: Adapt to use your actual default value
}

}
