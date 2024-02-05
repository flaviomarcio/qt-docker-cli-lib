#pragma once

#include <QObject>
#include "qt-docker-global.h"

namespace QtDockerCli {

class Container;
class Image;
class Service;
class Node;

//!
//! \brief The Actions class
//!
//! ref
//!     https://docs.docker.com/engine/reference/commandline/
class QT_DOCKER_CLI_LIB_EXPORT Actions: public QObject
{
    Q_OBJECT
public:
    explicit Actions(QObject *parent=nullptr);
};


}
