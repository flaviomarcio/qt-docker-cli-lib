#pragma once

#include <QObject>
#include "qt-docker-global.h"

namespace QtDockerCli {


class Container;
class Image;
class Service;
class Node;

//!
//! \brief The Instance class
//!
class QT_DOCKER_CLI_LIB_EXPORT Instance: public QObject
{
    Q_OBJECT
public:
    explicit Instance(QObject *parent=nullptr);
};


}
