#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT Port: public Object
{
    Q_OBJECT
public:
    explicit Port(QObject *parent=nullptr);
};


}
