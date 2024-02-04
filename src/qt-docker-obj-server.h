#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Server class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
class QT_DOCKER_CLI_LIB_EXPORT Server: public Object
{
    Q_OBJECT
public:
    explicit Server(QObject *parent=nullptr);
};

}
