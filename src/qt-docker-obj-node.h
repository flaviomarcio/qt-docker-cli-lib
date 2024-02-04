#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Volume class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/engine/reference/commandline/node/
class QT_DOCKER_CLI_LIB_EXPORT Node: public Object
{
    Q_OBJECT
public:
    explicit Node(QObject *parent=nullptr);
};

}
