#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Service class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/engine/reference/commandline/service/
class QT_DOCKER_CLI_LIB_EXPORT Service: public Object
{
    Q_OBJECT
public:
    explicit Service(QObject *parent=nullptr);
};
//**
// "Driver": "local",
// "Labels": {},
// "Mountpoint": "/var/lib/docker/volumes/my-vol/_data",
// "Name": "my-vol",
// "Options": {},
// "Scope": "local"

}


