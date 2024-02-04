#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT Deploy: public Object
{
    Q_OBJECT
public:
    explicit Deploy(QObject *parent=nullptr);
};


}
