#pragma once

#include <QVariant>
#include <QVariantHash>
#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Environment class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
class QT_DOCKER_CLI_LIB_EXPORT Environments: public Object
{
    Q_OBJECT
    Q_PROPERTY(QVariantHash envs READ envs WRITE setEnvs RESET resetEnvs NOTIFY envsChanged FINAL)
public:
    Q_INVOKABLE explicit Environments(QObject *parent=nullptr);

    QVariantHash envs() const;
    void setEnvs(const QVariantHash &newEnvs);
    void resetEnvs();

signals:
    void envsChanged();
private:
    QVariantHash _envs;
};

}
