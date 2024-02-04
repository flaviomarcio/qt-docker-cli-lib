#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The ComposeV3 class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/compose/
class QT_DOCKER_CLI_LIB_EXPORT ComposeV3: public Object
{
    Q_OBJECT
public:
    explicit ComposeV3(QObject *parent=nullptr);
};

}
