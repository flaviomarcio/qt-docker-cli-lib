#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT Network: public Object
{
    Q_OBJECT
public:
    explicit Network(QObject *parent=nullptr);
};


}
