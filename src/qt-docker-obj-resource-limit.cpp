#include "qt-docker-obj-resource-limit.h"

namespace QtDockerCli {

ResourceLimit::ResourceLimit(QObject *parent):Object{parent}{

}

QVariant ResourceLimit::cpu() const
{
    return _cpu;
}

void ResourceLimit::setCpu(const QVariant &newCpu)
{
    if (_cpu == newCpu)
        return;
    _cpu = newCpu;
    emit cpuChanged();
}

void ResourceLimit::resetCpu()
{
    setCpu({});
}

QVariant ResourceLimit::memory() const
{
    return _memory;
}

void ResourceLimit::setMemory(const QVariant &newMemory)
{
    if (_memory == newMemory)
        return;
    _memory = newMemory;
    emit memoryChanged();
}

void ResourceLimit::resetMemory()
{
    setMemory({});
}

}
