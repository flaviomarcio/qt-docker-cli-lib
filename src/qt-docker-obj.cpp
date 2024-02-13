#include "qt-docker-obj.h"
#include "../3rdparty/qstm/src/qstm_util_variant.h"

namespace QtDockerCli {

static const auto __ID="ID";
static const auto __Name="Name";

class ObjectPvt:public QObject{
public:
    Object *parent;
    QUuid objectId;
    explicit ObjectPvt(Object *parent):QObject{parent}{
    }
};

Object::Object(QObject *parent):QStm::ObjectWrapper{parent}, p{new ObjectPvt{this}}{
}

QUuid Object::objectId() const
{
    if(!p->objectId.isNull())
        return p->objectId;

    Q_DECLARE_VU;
    auto vId=this->property(__ID);
    if(!vId.isNull() && vId.isValid())
        p->objectId=vu.toMd5Uuid(vId);
    else {
        vId=this->property(__Name);
        if(!vId.isNull() && vId.isValid())
            p->objectId=vu.toMd5Uuid(vId);
    }

    return p->objectId;
}

void Object::setObjectId(const QUuid &newId)
{
    if (p->objectId == newId)
        return;
    p->objectId = newId;
    emit objectIdChanged();
}

void Object::resetObjectId()
{
    setObjectId({});
}

}
