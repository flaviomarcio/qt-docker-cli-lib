#include "qt-docker-obj-node.h"

namespace QtDockerCli {

Node::Node(QObject *parent):Object{parent}{

}

QString Node::id() const
{
    return _id;
}

void Node::setId(const QString &newId)
{
    if (_id == newId)
        return;
    _id = newId;
    emit idChanged();
}

void Node::resetId()
{
    setId({}); 
}

QVariantHash Node::version() const
{
    return _version;
}

void Node::setVersion(const QVariantHash &newVersion)
{
    if (_version == newVersion)
        return;
    _version = newVersion;
    emit versionChanged();
}

void Node::resetVersion()
{
    setVersion({}); 
}

QDateTime Node::createdAt() const
{
    return _createdAt;
}

void Node::setCreatedAt(const QDateTime &newCreatedAt)
{
    if (_createdAt == newCreatedAt)
        return;
    _createdAt = newCreatedAt;
    emit createdAtChanged();
}

void Node::resetCreatedAt()
{
    setCreatedAt({}); 
}

QDateTime Node::updatedAt() const
{
    return _updatedAt;
}

void Node::setUpdatedAt(const QDateTime &newUpdatedAt)
{
    if (_updatedAt == newUpdatedAt)
        return;
    _updatedAt = newUpdatedAt;
    emit updatedAtChanged();
}

void Node::resetUpdatedAt()
{
    setUpdatedAt({}); 
}

QVariantHash Node::spec() const
{
    return _spec;
}

void Node::setSpec(const QVariantHash &newSpec)
{
    if (_spec == newSpec)
        return;
    _spec = newSpec;
    emit specChanged();
}

void Node::resetSpec()
{
    setSpec({}); 
}

QVariantHash Node::description() const
{
    return _description;
}

void Node::setDescription(const QVariantHash &newDescription)
{
    if (_description == newDescription)
        return;
    _description = newDescription;
    emit descriptionChanged();
}

void Node::resetDescription()
{
    setDescription({}); 
}

QVariantHash Node::status() const
{
    return _status;
}

void Node::setStatus(const QVariantHash &newStatus)
{
    if (_status == newStatus)
        return;
    _status = newStatus;
    emit statusChanged();
}

void Node::resetStatus()
{
    setStatus({}); 
}

QVariantHash Node::managerStatus() const
{
    return _managerStatus;
}

void Node::setManagerStatus(const QVariantHash &newManagerStatus)
{
    if (_managerStatus == newManagerStatus)
        return;
    _managerStatus = newManagerStatus;
    emit managerStatusChanged();
}

void Node::resetManagerStatus()
{
    setManagerStatus({}); 
}

}
