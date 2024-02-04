#include "qt-docker-obj-labels.h"

namespace QtDockerCli {

Labels::Labels(QObject *parent):Object{parent}{

}

QVariantHash Labels::labels() const
{
    return _labels;
}

void Labels::setLabels(const QVariantHash &newLabels)
{
    if (_labels == newLabels)
        return;
    _labels = newLabels;
    emit labelsChanged();
}

void Labels::resetLabels()
{
    setLabels({}); // TODO: Adapt to use your actual default value
}

}
