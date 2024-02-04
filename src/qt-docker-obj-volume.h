#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT Volume: public Object
{
    Q_OBJECT
public:
    explicit Volume(QObject *parent=nullptr);
};

}
