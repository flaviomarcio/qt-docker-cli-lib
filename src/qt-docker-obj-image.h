#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT Image: public Object
{
    Q_OBJECT
public:
    explicit Image(QObject *parent=nullptr);
};


}
