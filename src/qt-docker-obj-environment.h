#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT Environment: public Object
{
    Q_OBJECT
public:
    explicit Environment(QObject *parent=nullptr);
};


}
