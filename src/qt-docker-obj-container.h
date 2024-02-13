#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Container class
//!
//! ref
//!     https://docs.docker.com/engine/api/v1.44/
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/engine/reference/commandline/container/
class QT_DOCKER_CLI_LIB_EXPORT Container: public Object
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId RESET resetId NOTIFY idChanged FINAL)
    Q_PROPERTY(QStringList names READ names WRITE setNames RESET resetNames NOTIFY namesChanged FINAL)
    Q_PROPERTY(QString image READ image WRITE setImage RESET resetImage NOTIFY imageChanged FINAL)
    Q_PROPERTY(QString imageID READ imageID WRITE setImageID RESET resetImageID NOTIFY imageIDChanged FINAL)
    Q_PROPERTY(QString command READ command WRITE setCommand RESET resetCommand NOTIFY commandChanged FINAL)
    Q_PROPERTY(QString created READ created WRITE setCreated RESET resetCreated NOTIFY createdChanged FINAL)
    Q_PROPERTY(QVariantList ports READ ports WRITE setPorts RESET resetPorts NOTIFY portsChanged FINAL)
    Q_PROPERTY(QVariantHash labels READ labels WRITE setLabels RESET resetLabels NOTIFY labelsChanged FINAL)
    Q_PROPERTY(QString state READ state WRITE setState RESET resetState NOTIFY stateChanged FINAL)
    Q_PROPERTY(QString status READ status WRITE setStatus RESET resetStatus NOTIFY statusChanged FINAL)
    Q_PROPERTY(QVariantHash hostConfig READ hostConfig WRITE setHostConfig RESET resetHostConfig NOTIFY hostConfigChanged FINAL)
    Q_PROPERTY(QVariantHash networkSettings READ networkSettings WRITE setNetworkSettings RESET resetNetworkSettings NOTIFY networkSettingsChanged FINAL)
    Q_PROPERTY(QVariantList mounts READ mounts WRITE setMounts RESET resetMounts NOTIFY mountsChanged FINAL)

    Q_DOCKER_OBJECT_ID_NAME(id)
public:
    Q_INVOKABLE explicit Container(QObject *parent=nullptr);
    QString id() const;
    void setId(const QString &newId);
    void resetId();

    QStringList names() const;
    void setNames(const QStringList &newNames);
    void resetNames();

    QString image() const;
    void setImage(const QString &newImage);
    void resetImage();

    QString imageID() const;
    void setImageID(const QString &newImageID);
    void resetImageID();

    QString command() const;
    void setCommand(const QString &newCommand);
    void resetCommand();

    QString created() const;
    void setCreated(const QString &newCreated);
    void resetCreated();

    QVariantList ports() const;
    void setPorts(const QVariantList &newPorts);
    void resetPorts();

    QVariantHash labels() const;
    void setLabels(const QVariantHash &newLabels);
    void resetLabels();

    QString state() const;
    void setState(const QString &newState);
    void resetState();

    QString status() const;
    void setStatus(const QString &newStatus);
    void resetStatus();

    QVariantHash hostConfig() const;
    void setHostConfig(const QVariantHash &newHostConfig);
    void resetHostConfig();

    QVariantHash networkSettings() const;
    void setNetworkSettings(const QVariantHash &newNetworkSettings);
    void resetNetworkSettings();

    QVariantList mounts() const;
    void setMounts(const QVariantList &newMounts);
    void resetMounts();

signals:
    void idChanged();

    void namesChanged();

    void imageChanged();

    void imageIDChanged();

    void commandChanged();

    void createdChanged();

    void portsChanged();

    void labelsChanged();

    void stateChanged();

    void statusChanged();

    void hostConfigChanged();

    void networkSettingsChanged();

    void mountsChanged();

private:
    QString _id;
    QStringList _names;
    QString _image;
    QString _imageID;
    QString _command;
    QString _created;
    QVariantList _ports;
    QVariantHash _labels;
    QString _state;
    QString _status;
    QVariantHash _hostConfig;
    QVariantHash _networkSettings;
    QVariantList _mounts;
};

}
