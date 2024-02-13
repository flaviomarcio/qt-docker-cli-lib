#include "qt-docker-obj-service.h"

namespace QtDockerCli {

Service::Service(QObject *parent):Object{parent}{

}

QString Service::id() const
{
    return _id;
}

void Service::setId(const QString &newId)
{
    if (_id == newId)
        return;
    _id = newId;
    emit idChanged();
}

void Service::resetId()
{
    setId({});
}

QVariantHash Service::version() const
{
    return _version;
}

void Service::setVersion(const QVariantHash &newVersion)
{
    if (_version == newVersion)
        return;
    _version = newVersion;
    emit versionChanged();
}

void Service::resetVersion()
{
    setVersion({});
}

QDateTime Service::createdAt() const
{
    return _createdAt;
}

void Service::setCreatedAt(const QDateTime &newCreatedAt)
{
    if (_createdAt == newCreatedAt)
        return;
    _createdAt = newCreatedAt;
    emit createdAtChanged();
}

void Service::resetCreatedAt()
{
    setCreatedAt({});
}

QDateTime Service::updatedAt() const
{
    return _updatedAt;
}

void Service::setUpdatedAt(const QDateTime &newUpdatedAt)
{
    if (_updatedAt == newUpdatedAt)
        return;
    _updatedAt = newUpdatedAt;
    emit updatedAtChanged();
}

void Service::resetUpdatedAt()
{
    setUpdatedAt({});
}

QVariantHash Service::spec() const
{
    return _spec;
}

void Service::setSpec(const QVariantHash &newSpec)
{
    if (_spec == newSpec)
        return;
    _spec = newSpec;
    emit specChanged();
}

void Service::resetSpec()
{
    setSpec({});
}

QVariantHash Service::endpoint() const
{
    return _endpoint;
}

void Service::setEndpoint(const QVariantHash &newEndpoint)
{
    if (_endpoint == newEndpoint)
        return;
    _endpoint = newEndpoint;
    emit endpointChanged();
}

void Service::resetEndpoint()
{
    setEndpoint({});
}

}
