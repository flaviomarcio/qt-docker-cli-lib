#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT Container: public Object
{
    Q_OBJECT
public:
    explicit Container(QObject *parent=nullptr);
};


}
