#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT Service: public Object
{
    Q_OBJECT
public:
    explicit Service(QObject *parent=nullptr);
};


}
