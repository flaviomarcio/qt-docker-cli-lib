#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Image class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/engine/reference/commandline/image/
class QT_DOCKER_CLI_LIB_EXPORT Image: public Object
{
    Q_OBJECT
public:
    explicit Image(QObject *parent=nullptr);
};


}
