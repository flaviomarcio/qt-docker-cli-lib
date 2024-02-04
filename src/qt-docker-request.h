#pragma once

#include <QObject>
#include "qt-docker-global.h"

namespace QtDockerCli {

//!
//! \brief The Request class
//!
class QT_DOCKER_CLI_LIB_EXPORT Request: public QObject
{
    Q_OBJECT
public:
    explicit Request(QObject *parent=nullptr);
};

}
