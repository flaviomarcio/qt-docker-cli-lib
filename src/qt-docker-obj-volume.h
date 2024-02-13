#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Volume class
//!
//! ref
//!     https://docs.docker.com/engine/api/v1.44/
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/storage/volumes/
class QT_DOCKER_CLI_LIB_EXPORT Volume: public Object
{
    Q_OBJECT
    Q_PROPERTY(QDateTime createdAt READ createdAt WRITE setCreatedAt RESET resetCreatedAt NOTIFY createdAtChanged FINAL)
    Q_PROPERTY(QString driver READ driver WRITE setDriver RESET resetDriver NOTIFY driverChanged FINAL)
    Q_PROPERTY(QVariantHash labels READ labels WRITE setLabels RESET resetLabels NOTIFY labelsChanged FINAL)
    Q_PROPERTY(QString mountPoint READ mountPoint WRITE setMountPoint RESET resetMountPoint NOTIFY mountPointChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QVariantHash options READ options WRITE setOptions RESET resetOptions NOTIFY optionsChanged FINAL)
    Q_PROPERTY(QString scope READ scope WRITE setScope RESET resetScope NOTIFY scopeChanged FINAL)

    Q_DOCKER_OBJECT_ID_NAME(name)
public:
    Q_INVOKABLE explicit Volume(QObject *parent=nullptr);

    //!
    //! \brief createdAt
    //! \return
    //!
    QDateTime createdAt() const;
    void setCreatedAt(const QDateTime &newCreatedAt);
    void resetCreatedAt();

    //!
    //! \brief driver
    //! \return
    //!
    QString driver() const;
    void setDriver(const QString &newDriver);
    void resetDriver();

    //!
    //! \brief labels
    //! \return
    //!
    QVariantHash labels() const;
    void setLabels(const QVariantHash &newLabels);
    void resetLabels();

    //!
    //! \brief mountPoint
    //! \return
    //!
    QString mountPoint() const;
    void setMountPoint(const QString &newMountPoint);
    void resetMountPoint();

    //!
    //! \brief name
    //! \return
    //!
    QString name() const;
    void setName(const QString &newName);
    void resetName();

    //!
    //! \brief options
    //! \return
    //!
    QVariantHash options() const;
    void setOptions(const QVariantHash &newOptions);
    void resetOptions();

    //!
    //! \brief scope
    //! \return
    //!
    QString scope() const;
    void setScope(const QString &newScope);
    void resetScope();

signals:
    void driverChanged();

    void labelsChanged();

    void mountPointChanged();

    void nameChanged();

    void optionsChanged();

    void scopeChanged();

    void createdAtChanged();

private:
    QDateTime _createdAt;
    QString _driver;
    QVariantHash _labels;
    QString _mountPoint;
    QString _name;
    QVariantHash _options;
    QString _scope;
};

}
