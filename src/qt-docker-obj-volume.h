#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Volume class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/storage/volumes/
class QT_DOCKER_CLI_LIB_EXPORT Volume: public Object
{
    Q_OBJECT
public:
    explicit Volume(QObject *parent=nullptr);
// "Driver": "local",
// "Labels": {},
// "Mountpoint": "/var/lib/docker/volumes/my-vol/_data",
// "Name": "my-vol",
// "Options": {},
// "Scope": "local"
};

}
