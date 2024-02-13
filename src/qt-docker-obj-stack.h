#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Stack class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/engine/reference/commandline/stack/
class QT_DOCKER_CLI_LIB_EXPORT Stack: public Object
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Stack(QObject *parent=nullptr);

};


}
