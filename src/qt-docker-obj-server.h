#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Server class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
class QT_DOCKER_CLI_LIB_EXPORT Server: public Object
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Server(QObject *parent=nullptr);
    QString name() const;
    void setName(const QString &newName);
    void resetName();

signals:
    void nameChanged();

private:
    QString _name;
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged FINAL)
};

}
