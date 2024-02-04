#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Mount class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/storage/bind-mounts/
class QT_DOCKER_CLI_LIB_EXPORT Mount: public Object
{
    Q_OBJECT
    Q_PROPERTY(Type type READ type WRITE setType RESET resetType NOTIFY typeChanged FINAL)
    Q_PROPERTY(QString source READ source WRITE setSource RESET resetSource NOTIFY sourceChanged FINAL)
    Q_PROPERTY(QString target READ target WRITE setTarget RESET resetTarget NOTIFY targetChanged FINAL)
public:
    enum Type{bind,volume,tmpfs};
    Q_ENUM(Type)
    explicit Mount(QObject *parent=nullptr);

    Type type() const;
    void setType(Type newType);
    void resetType();

    QString source() const;
    void setSource(const QString &newSource);
    void resetSource();

    QString target() const;
    void setTarget(const QString &newTarget);
    void resetTarget();

signals:
    void typeChanged();

    void sourceChanged();

    void targetChanged();

private:
    Type _type;
    QString _source;
    QString _target;
};

}
