#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT Stack: public Object
{
    Q_OBJECT
public:
    explicit Stack(QObject *parent=nullptr);
};


}
