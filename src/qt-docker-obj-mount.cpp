#include "qt-docker-obj-mount.h"

namespace QtDockerCli {

Mount::Mount(QObject *parent):Object{parent}{

}

Mount::Type Mount::type() const
{
    return _type;
}

void Mount::setType(Mount::Type newType)
{
    if (_type == newType)
        return;
    _type = newType;
    emit typeChanged();
}

void Mount::resetType()
{
    setType({});
}

QString Mount::source() const
{
    return _source;
}

void Mount::setSource(const QString &newSource)
{
    if (_source == newSource)
        return;
    _source = newSource;
    emit sourceChanged();
}

void Mount::resetSource()
{
    setSource({});
}

QString Mount::target() const
{
    return _target;
}

void Mount::setTarget(const QString &newTarget)
{
    if (_target == newTarget)
        return;
    _target = newTarget;
    emit targetChanged();
}

void Mount::resetTarget()
{
    setTarget({});
}

}
