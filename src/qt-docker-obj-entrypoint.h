#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT EntryPoint: public Object
{
    Q_OBJECT
public:
    explicit EntryPoint(QObject *parent=nullptr);
};


}
