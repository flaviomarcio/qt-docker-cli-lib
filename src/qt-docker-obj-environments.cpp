#include "qt-docker-obj-environments.h"

namespace QtDockerCli {

Environments::Environments(QObject *parent):Object{parent}{

}

QVariantHash Environments::envs() const
{
    return _envs;
}

void Environments::setEnvs(const QVariantHash &newEnvs)
{
    if (_envs == newEnvs)
        return;
    _envs = newEnvs;
    emit envsChanged();
}

void Environments::resetEnvs()
{
    setEnvs({}); // TODO: Adapt to use your actual default value
}

}
