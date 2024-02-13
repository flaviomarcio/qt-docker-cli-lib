#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {
//!
//! \brief The Network class
//!
//! ref
//!     https://docs.docker.com/engine/api/v1.44/
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     ref https://docs.docker.com/network
//!     ref https://docs.docker.com/network/#drivers
class QT_DOCKER_CLI_LIB_EXPORT Network: public Object
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString id READ id WRITE setId RESET resetId NOTIFY idChanged FINAL)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated RESET resetCreated NOTIFY createdChanged FINAL)
    Q_PROPERTY(QString scope READ scope WRITE setScope RESET resetScope NOTIFY scopeChanged FINAL)
    Q_PROPERTY(Driver driver READ driver WRITE setDriver RESET resetDriver NOTIFY driverChanged FINAL)
    Q_PROPERTY(bool enableIPv6 READ enableIPv6 WRITE setEnableIPv6 RESET resetEnableIPv6 NOTIFY enableIPv6Changed FINAL)
    Q_PROPERTY(QVariantHash IPAM READ IPAM WRITE setIPAM RESET resetIPAM NOTIFY IPAMChanged FINAL)
    Q_PROPERTY(bool internal READ internal WRITE setInternal RESET resetInternal NOTIFY internalChanged FINAL)
    Q_PROPERTY(bool attachable READ attachable WRITE setAttachable RESET resetAttachable NOTIFY attachableChanged FINAL)
    Q_PROPERTY(bool ingress READ ingress WRITE setIngress RESET resetIngress NOTIFY ingressChanged FINAL)
    Q_PROPERTY(QVariantHash configFrom READ configFrom WRITE setConfigFrom RESET resetConfigFrom NOTIFY configFromChanged FINAL)
    Q_PROPERTY(bool configOnly READ configOnly WRITE setConfigOnly RESET resetConfigOnly NOTIFY configOnlyChanged FINAL)
    Q_PROPERTY(QVariantHash containers READ containers WRITE setContainers RESET resetContainers NOTIFY containersChanged FINAL)
    Q_PROPERTY(QVariantHash options READ options WRITE setOptions RESET resetOptions NOTIFY optionsChanged FINAL)
    Q_PROPERTY(QVariantHash labels READ labels WRITE setLabels RESET resetLabels NOTIFY labelsChanged FINAL)

    Q_DOCKER_OBJECT_ID_NAME(id)
public:
    enum Driver{
         bridge  //The default network driver.
        ,host    //Remove network isolation between the container and the Docker host.
        ,none    //Completely isolate a container from the host and other containers.
        ,overlay //Overlay networks connect multiple Docker daemons together.
        ,ipvlan  //IPvlan networks provide full control over both IPv4 and IPv6 addressing.
        ,macvlan //Assign a MAC address to a container.
    };
    Q_ENUM(Driver)

    Q_INVOKABLE explicit Network(QObject *parent=nullptr);

    QString name() const;
    void setName(const QString &newName);
    void resetName();

    QString id() const;
    void setId(const QString &newId);
    void resetId();

    QDateTime created() const;
    void setCreated(const QVariant &newCreated);
    void resetCreated();

    QString scope() const;
    void setScope(const QString &newScope);
    void resetScope();

    Driver driver() const;
    void setDriver(Driver newDriver);
    void resetDriver();

    bool enableIPv6() const;
    void setEnableIPv6(bool newEnableIPv6);
    void resetEnableIPv6();

    QVariantHash IPAM() const;
    void setIPAM(const QVariantHash &newIPAM);
    void resetIPAM();

    bool internal() const;
    void setInternal(bool newInternal);
    void resetInternal();

    bool attachable() const;
    void setAttachable(bool newAttachable);
    void resetAttachable();

    bool ingress() const;
    void setIngress(bool newIngress);
    void resetIngress();

    QVariantHash configFrom() const;
    void setConfigFrom(const QVariantHash &newConfigFrom);
    void resetConfigFrom();

    bool configOnly() const;
    void setConfigOnly(bool newConfigOnly);
    void resetConfigOnly();

    QVariantHash containers() const;
    void setContainers(const QVariantHash &newContainers);
    void resetContainers();

    QVariantHash options() const;
    void setOptions(const QVariantHash &newOptions);
    void resetOptions();

    QVariantHash labels() const;
    void setLabels(const QVariantHash &newLabels);
    void resetLabels();

signals:
    void nameChanged();

    void idChanged();

    void createdChanged();

    void scopeChanged();

    void driverChanged();

    void enableIPv6Changed();

    void IPAMChanged();

    void internalChanged();

    void attachableChanged();

    void ingressChanged();

    void configFromChanged();

    void configOnlyChanged();

    void containersChanged();

    void optionsChanged();

    void labelsChanged();

private:
    QString _name;
    QString _id;
    QDateTime _created;
    QString _scope;
    Driver _driver;
    bool _enableIPv6;
    QVariantHash _IPAM;
    bool _internal;
    bool _attachable;
    bool _ingress;
    QVariantHash _configFrom;
    bool _configOnly;
    QVariantHash _containers;
    QVariantHash _options;
    QVariantHash _labels;
};



}
