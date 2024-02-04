#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Container class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/engine/reference/commandline/container/
class QT_DOCKER_CLI_LIB_EXPORT Container: public Object
{
    Q_OBJECT
public:
    explicit Container(QObject *parent=nullptr);
};


}
