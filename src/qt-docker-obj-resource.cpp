#include "qt-docker-obj-resource.h"

namespace QtDockerCli {

Resource::Resource(QObject *parent):Object{parent}{

}

ResourceLimit *Resource::resourceLimit() const
{
    return _resourceLimit;
}

void Resource::setResourceLimit(ResourceLimit *newResourceLimit)
{
    if (_resourceLimit == newResourceLimit)
        return;
    _resourceLimit = newResourceLimit;
    emit resourceLimitChanged();
}

void Resource::resetResourceLimit()
{
    setResourceLimit({});
}

}
