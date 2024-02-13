#pragma once

#include <QVariant>
#include <QVariantHash>
#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Labels class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
class QT_DOCKER_CLI_LIB_EXPORT Labels: public Object
{
    Q_OBJECT
    Q_PROPERTY(QVariantHash labels READ labels WRITE setLabels RESET resetLabels NOTIFY labelsChanged FINAL)
public:
    Q_INVOKABLE explicit Labels(QObject *parent=nullptr);

    QVariantHash labels() const;
    void setLabels(const QVariantHash &newLabels);
    void resetLabels();

signals:
    void labelsChanged();
private:
    QVariantHash _labels;
};

}
