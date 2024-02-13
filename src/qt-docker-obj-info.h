#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Info class
//!
//! ref
//!     https://docs.docker.com/engine/reference/commandline/system_info/
class QT_DOCKER_CLI_LIB_EXPORT Info: public Object
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Info(QObject *parent=nullptr);
};

}
