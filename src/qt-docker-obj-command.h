#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT Command: public Object
{
    Q_OBJECT
public:
    explicit Command(QObject *parent=nullptr);
};


}
