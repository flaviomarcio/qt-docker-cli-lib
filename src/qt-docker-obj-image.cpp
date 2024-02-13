#include "qt-docker-obj-image.h"

namespace QtDockerCli {

Image::Image(QObject *parent):Object{parent}{

}

int Image::containers() const
{
    return _containers;
}

void Image::setContainers(int newContainers)
{
    if (_containers == newContainers)
        return;
    _containers = newContainers;
    emit containersChanged();
}

void Image::resetContainers()
{
    setContainers({});
}

qlonglong Image::created() const
{
    return _created;
}

void Image::setCreated(qlonglong newCreated)
{
    if (_created == newCreated)
        return;
    _created = newCreated;
    emit createdChanged();
}

void Image::resetCreated()
{
    setCreated({});
}

QString Image::id() const
{
    return _id;
}

void Image::setId(const QString &newId)
{
    if (_id == newId)
        return;
    _id = newId;
    emit idChanged();
}

void Image::resetId()
{
    setId({});
}

QVariantHash Image::labels() const
{
    return _labels;
}

void Image::setLabels(const QVariantHash &newLabels)
{
    if (_labels == newLabels)
        return;
    _labels = newLabels;
    emit labelsChanged();
}

void Image::resetLabels()
{
    setLabels({});
}

QString Image::parentId() const
{
    return _parentId;
}

void Image::setParentId(const QString &newParentId)
{
    if (_parentId == newParentId)
        return;
    _parentId = newParentId;
    emit parentIdChanged();
}

void Image::resetParentId()
{
    setParentId({});
}

QStringList Image::repoDigests() const
{
    return _repoDigests;
}

void Image::setRepoDigests(const QStringList &newRepoDigests)
{
    if (_repoDigests == newRepoDigests)
        return;
    _repoDigests = newRepoDigests;
    emit repoDigestsChanged();
}

void Image::resetRepoDigests()
{
    setRepoDigests({});
}

QStringList Image::repoTags() const
{
    return _repoTags;
}

void Image::setRepoTags(const QStringList &newRepoTags)
{
    if (_repoTags == newRepoTags)
        return;
    _repoTags = newRepoTags;
    emit repoTagsChanged();
}

void Image::resetRepoTags()
{
    setRepoTags({});
}

qlonglong Image::sharedSize() const
{
    return _sharedSize;
}

void Image::setSharedSize(qlonglong newSharedSize)
{
    if (_sharedSize == newSharedSize)
        return;
    _sharedSize = newSharedSize;
    emit sharedSizeChanged();
}

void Image::resetSharedSize()
{
    setSharedSize({});
}

qlonglong Image::size() const
{
    return _size;
}

void Image::setSize(qlonglong newSize)
{
    if (_size == newSize)
        return;
    _size = newSize;
    emit sizeChanged();
}

void Image::resetSize()
{
    setSize({});
}

}
