#pragma once

#include <QObject>
#include <QStm>
#include "qt-docker-global.h"

namespace QtDockerCli {

//!
//! \brief The Object class
//!
class QT_DOCKER_CLI_LIB_EXPORT Object: public QStm::ObjectWrapper
{
    Q_OBJECT
public:
    explicit Object(QObject *parent=nullptr);
};


}
