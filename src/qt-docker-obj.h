#pragma once

#include <QObject>
#include "qt-docker-global.h"

namespace QtDockerCli {

class QT_DOCKER_CLI_LIB_EXPORT Object: public QObject
{
    Q_OBJECT
public:
    explicit Object(QObject *parent=nullptr);
};


}
