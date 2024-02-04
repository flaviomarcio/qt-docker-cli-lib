#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {
//!
//! \brief The Network class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     ref https://docs.docker.com/network
//!     ref https://docs.docker.com/network/#drivers
class QT_DOCKER_CLI_LIB_EXPORT Network: public Object
{
    Q_OBJECT
public:
    enum Drivers{
         bridge  //The default network driver.
        ,host    //Remove network isolation between the container and the Docker host.
        ,none    //Completely isolate a container from the host and other containers.
        ,overlay //Overlay networks connect multiple Docker daemons together.
        ,ipvlan  //IPvlan networks provide full control over both IPv4 and IPv6 addressing.
        ,macvlan //Assign a MAC address to a container.
    };
    Q_ENUM(Drivers)
    explicit Network(QObject *parent=nullptr);
};


}
