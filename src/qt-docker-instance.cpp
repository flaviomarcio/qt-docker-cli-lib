#include "qt-docker-instance.h"
#include "qt-docker-request.h"
#include "../3rdparty/qstm/src/qstm_util_meta_object.h"

namespace QtDockerCli {

static const auto __localhost="localhost";

class InstancePvt:public QObject{
public:
    Instance *parent;
    QList<Volume*> volumes;
    QString url;
    Request __rq;
    explicit InstancePvt(Instance *parent):QObject{parent}, parent{parent}{
    }


    Request &rq(){
        //https://docs.docker.com/engine/reference/commandline/login/#credentials-store
            __rq
                .call("http://localhost/v1.44/info")
                .wait()
                .response()
            ;
        return __rq;
    }


    void clear()
    {
        this->url=__localhost;
        this->clearData();
        this->__rq.clear();
    }

#define __clear_list(OBJ)auto aux=OBJ;OBJ.clear();qDeleteAll(aux);

    void clearData()
    {
        __clear_list(this->volumes);
    }

    void refresh()
    {
        this->clearData();
        this->loadVolumes();
    }

    void loadVolumes()
    {
        this->rq().call()
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
    return *this;
}

const QList<Volume *> &Instance::volumes() const
{
    return p->volumes;
}

}
