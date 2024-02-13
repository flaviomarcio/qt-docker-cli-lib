#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Command class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
class QT_DOCKER_CLI_LIB_EXPORT Command: public Object
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Command(QObject *parent=nullptr);
};


}
