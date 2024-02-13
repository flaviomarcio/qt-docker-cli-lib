#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Swarm class
//!
//! ref
//!     https://docs.docker.com/engine/api/v1.44/
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/engine/reference/commandline/swarm/
class QT_DOCKER_CLI_LIB_EXPORT Swarm: public Object
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId RESET resetId NOTIFY idChanged FINAL)
    Q_PROPERTY(QVariantHash version READ version WRITE setVersion RESET resetVersion NOTIFY versionChanged FINAL)
    Q_PROPERTY(QDateTime createdAt READ createdAt WRITE setCreatedAt RESET resetCreatedAt NOTIFY createdAtChanged FINAL)
    Q_PROPERTY(QDateTime updatedAt READ updatedAt WRITE setUpdatedAt RESET resetUpdatedAt NOTIFY updatedAtChanged FINAL)
    Q_PROPERTY(QVariantHash spec READ spec WRITE setSpec RESET resetSpec NOTIFY specChanged FINAL)
    Q_PROPERTY(QString subnetSize READ subnetSize WRITE setSubnetSize RESET resetSubnetSize NOTIFY subnetSizeChanged FINAL)
    Q_PROPERTY(int dataPathPort READ dataPathPort WRITE setDataPathPort RESET resetDataPathPort NOTIFY dataPathPortChanged FINAL)
    Q_PROPERTY(QStringList defaultAddrPool READ defaultAddrPool WRITE setDefaultAddrPool RESET resetDefaultAddrPool NOTIFY defaultAddrPoolChanged FINAL)
    Q_PROPERTY(bool rootRotationInProgress READ rootRotationInProgress WRITE setRootRotationInProgress RESET resetRootRotationInProgress NOTIFY rootRotationInProgressChanged FINAL)
    Q_PROPERTY(QVariantHash TLSInfo READ TLSInfo WRITE setTLSInfo RESET resetTLSInfo NOTIFY TLSInfoChanged FINAL)
    Q_PROPERTY(QVariantHash joinTokens READ joinTokens WRITE setJoinTokens RESET resetJoinTokens NOTIFY joinTokensChanged FINAL)

    Q_DOCKER_OBJECT_ID_NAME(id)
public:
    Q_INVOKABLE explicit Swarm(QObject *parent=nullptr);
    QString id() const;
    void setId(const QString &newId);
    void resetId();

    QVariantHash version() const;
    void setVersion(const QVariantHash &newVersion);
    void resetVersion();

    QDateTime createdAt() const;
    void setCreatedAt(const QDateTime &newCreatedAt);
    void resetCreatedAt();

    QDateTime updatedAt() const;
    void setUpdatedAt(const QDateTime &newUpdatedAt);
    void resetUpdatedAt();

    QVariantHash spec() const;
    void setSpec(const QVariantHash &newSpec);
    void resetSpec();

    QString subnetSize() const;
    void setSubnetSize(const QString &newSubnetSize);
    void resetSubnetSize();

    int dataPathPort() const;
    void setDataPathPort(int newDataPathPort);
    void resetDataPathPort();

    QStringList defaultAddrPool() const;
    void setDefaultAddrPool(const QStringList &newDefaultAddrPool);
    void resetDefaultAddrPool();

    bool rootRotationInProgress() const;
    void setRootRotationInProgress(bool newRootRotationInProgress);
    void resetRootRotationInProgress();

    QVariantHash TLSInfo() const;
    void setTLSInfo(const QVariantHash &newTLSInfo);
    void resetTLSInfo();

    QVariantHash joinTokens() const;
    void setJoinTokens(const QVariantHash &newJoinTokens);
    void resetJoinTokens();

signals:
    void idChanged();

    void versionChanged();

    void createdAtChanged();

    void updatedAtChanged();

    void specChanged();

    void endpointChanged();

    void subnetSizeChanged();

    void dataPathPortChanged();

    void defaultAddrPoolChanged();

    void rootRotationInProgressChanged();

    void TLSInfoChanged();

    void joinTokensChanged();

private:
    QString _id;
    QVariantHash _version;
    QDateTime _createdAt;
    QDateTime _updatedAt;
    QVariantHash _spec;
    QString _subnetSize;
    int _dataPathPort;
    QStringList _defaultAddrPool;
    bool _rootRotationInProgress;
    QVariantHash _TLSInfo;
    QVariantHash _joinTokens;
};


}


