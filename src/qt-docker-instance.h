#pragma once

#include <QObject>
#include <QList>
#include <QUrl>
#include <QUuid>
#include <QStringList>
#include <QVariantList>
#include <QVariantMap>
#include <QVariantHash>
#include "qt-docker-global.h"
#include "qt-docker-obj-volume.h"

namespace QtDockerCli {

class InstancePvt;

// class Container;
// class Image;
// class Service;
// class Node;

//!
//! \brief The Instance class
//!
class QT_DOCKER_CLI_LIB_EXPORT Instance: public QObject
{
    Q_OBJECT
public:
    explicit Instance(QObject *parent=nullptr);
private:
    InstancePvt *p=nullptr;

    Instance &clear();
    Instance &refresh();



    const QList<Volume*> &volumes()const;
};


}
