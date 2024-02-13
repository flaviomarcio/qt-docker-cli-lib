#include "qt-docker-obj-network.h"

namespace QtDockerCli {

Network::Network(QObject *parent):Object{parent}{

}

QString Network::name() const
{
    return _name;
}

void Network::setName(const QString &newName)
{
    if (_name == newName)
        return;
    _name = newName;
    emit nameChanged();
}

void Network::resetName()
{
    setName({});
}

QString Network::id() const
{
    return _id;
}

void Network::setId(const QString &newId)
{
    if (_id == newId)
        return;
    _id = newId;
    emit idChanged();
}

void Network::resetId()
{
    setId({});
}

QDateTime Network::created() const
{
    return _created;
}

void Network::setCreated(const QVariant &newCreated)
{
    if (_created == newCreated.toDateTime())
        return;
    _created = newCreated.toDateTime();
    emit createdChanged();
}

void Network::resetCreated()
{
    setCreated({});
}

QString Network::scope() const
{
    return _scope;
}

void Network::setScope(const QString &newScope)
{
    if (_scope == newScope)
        return;
    _scope = newScope;
    emit scopeChanged();
}

void Network::resetScope()
{
    setScope({});
}

Network::Driver Network::driver() const
{
    return _driver;
}

void Network::setDriver(Driver newDriver)
{
    if (_driver == newDriver)
        return;
    _driver = newDriver;
    emit driverChanged();
}

void Network::resetDriver()
{
    setDriver({});
}

bool Network::enableIPv6() const
{
    return _enableIPv6;
}

void Network::setEnableIPv6(bool newEnableIPv6)
{
    if (_enableIPv6 == newEnableIPv6)
        return;
    _enableIPv6 = newEnableIPv6;
    emit enableIPv6Changed();
}

void Network::resetEnableIPv6()
{
    setEnableIPv6({});
}

QVariantHash Network::IPAM() const
{
    return _IPAM;
}

void Network::setIPAM(const QVariantHash &newIPAM)
{
    if (_IPAM == newIPAM)
        return;
    _IPAM = newIPAM;
    emit IPAMChanged();
}

void Network::resetIPAM()
{
    setIPAM({});
}

bool Network::internal() const
{
    return _internal;
}

void Network::setInternal(bool newInternal)
{
    if (_internal == newInternal)
        return;
    _internal = newInternal;
    emit internalChanged();
}

void Network::resetInternal()
{
    setInternal({});
}

bool Network::attachable() const
{
    return _attachable;
}

void Network::setAttachable(bool newAttachable)
{
    if (_attachable == newAttachable)
        return;
    _attachable = newAttachable;
    emit attachableChanged();
}

void Network::resetAttachable()
{
    setAttachable({});
}

bool Network::ingress() const
{
    return _ingress;
}

void Network::setIngress(bool newIngress)
{
    if (_ingress == newIngress)
        return;
    _ingress = newIngress;
    emit ingressChanged();
}

void Network::resetIngress()
{
    setIngress({});
}

QVariantHash Network::configFrom() const
{
    return _configFrom;
}

void Network::setConfigFrom(const QVariantHash &newConfigFrom)
{
    if (_configFrom == newConfigFrom)
        return;
    _configFrom = newConfigFrom;
    emit configFromChanged();
}

void Network::resetConfigFrom()
{
    setConfigFrom({});
}

bool Network::configOnly() const
{
    return _configOnly;
}

void Network::setConfigOnly(bool newConfigOnly)
{
    if (_configOnly == newConfigOnly)
        return;
    _configOnly = newConfigOnly;
    emit configOnlyChanged();
}

void Network::resetConfigOnly()
{
    setConfigOnly({});
}

QVariantHash Network::containers() const
{
    return _containers;
}

void Network::setContainers(const QVariantHash &newContainers)
{
    if (_containers == newContainers)
        return;
    _containers = newContainers;
    emit containersChanged();
}

void Network::resetContainers()
{
    setContainers({});
}

QVariantHash Network::options() const
{
    return _options;
}

void Network::setOptions(const QVariantHash &newOptions)
{
    if (_options == newOptions)
        return;
    _options = newOptions;
    emit optionsChanged();
}

void Network::resetOptions()
{
    setOptions({});
}

QVariantHash Network::labels() const
{
    return _labels;
}

void Network::setLabels(const QVariantHash &newLabels)
{
    if (_labels == newLabels)
        return;
    _labels = newLabels;
    emit labelsChanged();
}

void Network::resetLabels()
{
    setLabels({});
}

}
