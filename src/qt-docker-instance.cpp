#include "qt-docker-instance.h"
#include "qt-docker-request.h"
#include "../3rdparty/qstm/src/qstm_meta_items.h"
#include "../3rdparty/qstm/src/qstm_util_date.h"
#include <QMutex>

namespace QtDockerCli {

class InstancePvt:public QObject{
public:
    QMutex mutex;
    Instance *parent;
    RemoteHost remoteHost;
    QVariant refreshTimeOut;
    QHash<QByteArray,QDateTime> lastRefresh;
    QStm::MetaItems<Network> networks;
    QStm::MetaItems<Image> images;
    QStm::MetaItems<Volume> volumes;
    Swarm swarm;
    QStm::MetaItems<Node> nodes;
    QStm::MetaItems<Service> services;
    QStm::MetaItems<Container> containers;
    Request __rq;
    explicit InstancePvt(Instance *parent)
        :QObject{parent},
        parent{parent},
        remoteHost{parent},
        volumes{},
        __rq{parent}
    {
        remoteHost.clear();
        __rq.HTTP();

        QObject::connect(&__rq, &Request::started, parent, &Instance::started);
        QObject::connect(&__rq, &Request::connected, parent, &Instance::connected);
        QObject::connect(&__rq, &Request::fail, parent, &Instance::fail);
        QObject::connect(&__rq, &Request::finished, parent, &Instance::finished);
    }


    Request &rq(){
        //https://docs.docker.com/engine/reference/commandline/login/#credentials-store
        return __rq
            .clear()
            .settings(remoteHost.toHash())
            .path({});
    }


    void clear()
    {
        this->remoteHost.clear();
        this->clearData();
        this->__rq.clear();
    }

    void clearData()
    {
        volumes.clean();
    }

    bool canRefresh(const QByteArray &func){
        Q_DECLARE_DU;
        auto interval=du.parseInterval(this->refreshTimeOut).toInt();
        auto dt=this->lastRefresh.value(func);
        auto __return = (dt.isNull() || !dt.isValid() || dt<QDateTime::currentDateTime().addMSecs(interval));
        this->lastRefresh.insert(func, QDateTime::currentDateTime());
        return __return;
    }

    void refresh()
    {
        {
            QMutexLocker locker(&this->mutex);
            this->lastRefresh.clear();
            this->clearData();
        }
        this->loadNetworks();
        this->loadImages();
        this->loadVolumes();
        this->loadSwarm();
        this->loadNodes();
        this->loadServices();
        this->loadContainers();
    }

    QVariant loadByGET(const QByteArray &funcName, const QByteArray &path)
    {
        if(!canRefresh(funcName))
            return {};
        return this->rq()
                             .path(path)
                             .call()
                             .response()
                             .asVariant();
    }

    void loadNetworks()
    {
        auto &items=this->networks;
        items
            .clean()
            .itemsUpdate(loadByGET(__func__, "/networks"));
    }

    void loadImages()
    {
        auto &items=this->images;
        items
            .clean()
            .itemsUpdate(loadByGET(__func__, "/images/json"));
    }

    void loadVolumes()
    {
        auto &items=this->volumes;
        auto vItems=loadByGET(__func__, "/volumes").toHash().value("Volumes").toList();
        items
            .clean()
            .itemsUpdate(vItems);
    }

    void loadSwarm()
    {
        auto vData=loadByGET(__func__, "/swarm");
        this->swarm.clear();
        this->swarm.setValues(vData);
    }

    void loadNodes()
    {
        auto &items=this->nodes;
        items
            .clean()
            .itemsUpdate(loadByGET(__func__, "/nodes"));
    }

    void loadServices()
    {
        auto &items=this->services;
        items
            .clean()
            .itemsUpdate(loadByGET(__func__, "/services"));
    }

    void loadContainers()
    {
        auto &items=this->containers;
        items
            .clean()
            .itemsUpdate(loadByGET(__func__, "/containers/json"));
    }
};

Instance::Instance(QObject *parent):QObject{parent},p{new InstancePvt{this}}{
}

Instance &Instance::clear()
{
    p->clear();
    return *this;
}

Instance &Instance::refresh()
{
    p->refresh();
    emit refreshed();
    return *this;
}

RemoteHost &Instance::remoteHost()
{
    return p->remoteHost;
}

const QList<Network *> &Instance::networks() const
{
    return p->networks.items();
}

const QList<Image *> &Instance::images() const
{
    return p->images.items();
}

const QList<Volume *> &Instance::volumes() const
{
    return p->volumes.items();
}

Swarm &Instance::swarm()
{
    return p->swarm;
}

const QList<Node *> &Instance::nodes() const
{
    return p->nodes.items();
}

const QList<Service *> &Instance::services() const
{
    return p->services.items();
}

const QList<Container *> &Instance::containers() const
{
    return p->containers.items();
}

}
