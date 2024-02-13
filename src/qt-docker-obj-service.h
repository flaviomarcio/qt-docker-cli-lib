#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Service class
//!
//! ref
//!     https://docs.docker.com/engine/api/v1.44/
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/engine/reference/commandline/service/
class QT_DOCKER_CLI_LIB_EXPORT Service: public Object
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId RESET resetId NOTIFY idChanged FINAL)
    Q_PROPERTY(QVariantHash version READ version WRITE setVersion RESET resetVersion NOTIFY versionChanged FINAL)
    Q_PROPERTY(QDateTime createdAt READ createdAt WRITE setCreatedAt RESET resetCreatedAt NOTIFY createdAtChanged FINAL)
    Q_PROPERTY(QDateTime updatedAt READ updatedAt WRITE setUpdatedAt RESET resetUpdatedAt NOTIFY updatedAtChanged FINAL)
    Q_PROPERTY(QVariantHash spec READ spec WRITE setSpec RESET resetSpec NOTIFY specChanged FINAL)
    Q_PROPERTY(QVariantHash endpoint READ endpoint WRITE setEndpoint RESET resetEndpoint NOTIFY endpointChanged FINAL)

    Q_DOCKER_OBJECT_ID_NAME(id)
public:
    Q_INVOKABLE explicit Service(QObject *parent=nullptr);
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

    QVariantHash endpoint() const;
    void setEndpoint(const QVariantHash &newEndpoint);
    void resetEndpoint();

signals:
    void idChanged();

    void versionChanged();

    void createdAtChanged();

    void updatedAtChanged();

    void specChanged();

    void endpointChanged();

private:
    QString _id;
    QVariantHash _version;
    QDateTime _createdAt;
    QDateTime _updatedAt;
    QVariantHash _spec;
    QVariantHash _endpoint;
};


}


