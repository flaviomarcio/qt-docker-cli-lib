#pragma once

#include <QVariant>
#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The ResourceLimit class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/config/containers/resource_constraints/
class QT_DOCKER_CLI_LIB_EXPORT ResourceLimit: public Object
{
    Q_OBJECT
    Q_PROPERTY(QVariant cpu READ cpu WRITE setCpu RESET resetCpu NOTIFY cpuChanged FINAL)
    Q_PROPERTY(QVariant memory READ memory WRITE setMemory RESET resetMemory NOTIFY memoryChanged FINAL)
public:
    explicit ResourceLimit(QObject *parent=nullptr);
    QVariant cpu() const;
    void setCpu(const QVariant &newCpu);
    void resetCpu();

    QVariant memory() const;
    void setMemory(const QVariant &newMemory);
    void resetMemory();

signals:
    void cpuChanged();

    void memoryChanged();

private:
    QVariant _cpu;
    QVariant _memory;
};

}
