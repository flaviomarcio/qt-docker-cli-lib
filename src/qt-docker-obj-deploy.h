#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Deploy class
//!
class QT_DOCKER_CLI_LIB_EXPORT Deploy: public Object
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Deploy(QObject *parent=nullptr);
};

}
