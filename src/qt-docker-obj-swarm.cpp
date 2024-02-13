#include "qt-docker-obj-swarm.h"

namespace QtDockerCli {

Swarm::Swarm(QObject *parent):Object{parent}{

}

QString Swarm::id() const
{
    return _id;
}

void Swarm::setId(const QString &newId)
{
    if (_id == newId)
        return;
    _id = newId;
    emit idChanged();
}

void Swarm::resetId()
{
    setId({});
}

QVariantHash Swarm::version() const
{
    return _version;
}

void Swarm::setVersion(const QVariantHash &newVersion)
{
    if (_version == newVersion)
        return;
    _version = newVersion;
    emit versionChanged();
}

void Swarm::resetVersion()
{
    setVersion({});
}

QDateTime Swarm::createdAt() const
{
    return _createdAt;
}

void Swarm::setCreatedAt(const QDateTime &newCreatedAt)
{
    if (_createdAt == newCreatedAt)
        return;
    _createdAt = newCreatedAt;
    emit createdAtChanged();
}

void Swarm::resetCreatedAt()
{
    setCreatedAt({});
}

QDateTime Swarm::updatedAt() const
{
    return _updatedAt;
}

void Swarm::setUpdatedAt(const QDateTime &newUpdatedAt)
{
    if (_updatedAt == newUpdatedAt)
        return;
    _updatedAt = newUpdatedAt;
    emit updatedAtChanged();
}

void Swarm::resetUpdatedAt()
{
    setUpdatedAt({});
}

QVariantHash Swarm::spec() const
{
    return _spec;
}

void Swarm::setSpec(const QVariantHash &newSpec)
{
    if (_spec == newSpec)
        return;
    _spec = newSpec;
    emit specChanged();
}

void Swarm::resetSpec()
{
    setSpec({});
}

QString Swarm::subnetSize() const
{
    return _subnetSize;
}

void Swarm::setSubnetSize(const QString &newSubnetSize)
{
    if (_subnetSize == newSubnetSize)
        return;
    _subnetSize = newSubnetSize;
    emit subnetSizeChanged();
}

void Swarm::resetSubnetSize()
{
    setSubnetSize({}); // TODO: Adapt to use your actual default value
}

int Swarm::dataPathPort() const
{
    return _dataPathPort;
}

void Swarm::setDataPathPort(int newDataPathPort)
{
    if (_dataPathPort == newDataPathPort)
        return;
    _dataPathPort = newDataPathPort;
    emit dataPathPortChanged();
}

void Swarm::resetDataPathPort()
{
    setDataPathPort({}); // TODO: Adapt to use your actual default value
}

QStringList Swarm::defaultAddrPool() const
{
    return _defaultAddrPool;
}

void Swarm::setDefaultAddrPool(const QStringList &newDefaultAddrPool)
{
    if (_defaultAddrPool == newDefaultAddrPool)
        return;
    _defaultAddrPool = newDefaultAddrPool;
    emit defaultAddrPoolChanged();
}

void Swarm::resetDefaultAddrPool()
{
    setDefaultAddrPool({}); // TODO: Adapt to use your actual default value
}

bool Swarm::rootRotationInProgress() const
{
    return _rootRotationInProgress;
}

void Swarm::setRootRotationInProgress(bool newRootRotationInProgress)
{
    if (_rootRotationInProgress == newRootRotationInProgress)
        return;
    _rootRotationInProgress = newRootRotationInProgress;
    emit rootRotationInProgressChanged();
}

void Swarm::resetRootRotationInProgress()
{
    setRootRotationInProgress({}); // TODO: Adapt to use your actual default value
}

QVariantHash Swarm::TLSInfo() const
{
    return _TLSInfo;
}

void Swarm::setTLSInfo(const QVariantHash &newTLSInfo)
{
    if (_TLSInfo == newTLSInfo)
        return;
    _TLSInfo = newTLSInfo;
    emit TLSInfoChanged();
}

void Swarm::resetTLSInfo()
{
    setTLSInfo({}); // TODO: Adapt to use your actual default value
}

QVariantHash Swarm::joinTokens() const
{
    return _joinTokens;
}

void Swarm::setJoinTokens(const QVariantHash &newJoinTokens)
{
    if (_joinTokens == newJoinTokens)
        return;
    _joinTokens = newJoinTokens;
    emit joinTokensChanged();
}

void Swarm::resetJoinTokens()
{
    setJoinTokens({}); // TODO: Adapt to use your actual default value
}

}
