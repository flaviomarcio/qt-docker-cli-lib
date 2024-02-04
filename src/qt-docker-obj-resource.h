#pragma once

#include "qt-docker-obj.h"
#include "qt-docker-obj-resource-limit.h"

namespace QtDockerCli {
class ResourceLimit;
//!
//! \brief The Volume class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/config/containers/resource_constraints/
class QT_DOCKER_CLI_LIB_EXPORT Resource: public Object
{
    Q_OBJECT
    Q_PROPERTY(ResourceLimit *resourceLimit READ resourceLimit WRITE setResourceLimit RESET resetResourceLimit NOTIFY resourceLimitChanged FINAL)
public:
    explicit Resource(QObject *parent=nullptr);

    //!
    //! \brief resourceLimit
    //! \return
    //!
    ResourceLimit *resourceLimit() const;
    void setResourceLimit(ResourceLimit *newResourceLimit);
    void resetResourceLimit();

signals:
    void resourceLimitChanged();

private:
    ResourceLimit *_resourceLimit=nullptr;
};

}
