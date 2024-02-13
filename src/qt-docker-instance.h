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
#include "qt-docker-remote-host.h"
#include "qt-docker-obj-network.h"
#include "qt-docker-obj-volume.h"
#include "qt-docker-obj-image.h"
#include "qt-docker-obj-swarm.h"
#include "qt-docker-obj-node.h"
#include "qt-docker-obj-service.h"
#include "qt-docker-obj-container.h"

namespace QtDockerCli {

class InstancePvt;

//!
//! \brief The Instance class
//!
class QT_DOCKER_CLI_LIB_EXPORT Instance: public QObject
{
    Q_OBJECT
public:
    //!
    //! \brief Instance
    //! \param parent
    //!
    explicit Instance(QObject *parent=nullptr);

    //!
    //! \brief clear
    //! \return
    //!
    Instance &clear();

    //!
    //! \brief refresh
    //! \return
    //!
    Instance &refresh();

    //!
    //! \brief remoteHost
    //! \return
    //!
    RemoteHost &remoteHost();

    //!
    //! \brief networks
    //! \return
    //!
    const QList<Network*> &networks()const;

    //!
    //! \brief images
    //! \return
    //!
    const QList<Image*> &images()const;

    //!
    //! \brief volumes
    //! \return
    //!
    const QList<Volume*> &volumes()const;

    //!
    //! \brief swarm
    //! \return
    //!
    const Swarm &swarm()const;

    //!
    //! \brief nodes
    //! \return
    //!
    const QList<Node*> &nodes()const;

    //!
    //! \brief services
    //! \return
    //!
    const QList<Service*> &services()const;

    //!
    //! \brief containers
    //! \return
    //!
    const QList<Container*> &containers()const;
private:
    InstancePvt *p=nullptr;
signals:
    void started();
    void connected();
    void fail(QString message);
    void finished();
};


}
