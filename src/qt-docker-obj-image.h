#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Image class
//!
//! ref
//!     https://docs.docker.com/engine/api/v1.44/
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/engine/reference/commandline/image/
class QT_DOCKER_CLI_LIB_EXPORT Image: public Object
{
    Q_OBJECT
    Q_PROPERTY(int containers READ containers WRITE setContainers RESET resetContainers NOTIFY containersChanged FINAL)
    Q_PROPERTY(qlonglong created READ created WRITE setCreated RESET resetCreated NOTIFY createdChanged FINAL)
    Q_PROPERTY(QString id READ id WRITE setId RESET resetId NOTIFY idChanged FINAL)
    Q_PROPERTY(QVariantHash labels READ labels WRITE setLabels RESET resetLabels NOTIFY labelsChanged FINAL)
    Q_PROPERTY(QString parentId READ parentId WRITE setParentId RESET resetParentId NOTIFY parentIdChanged FINAL)
    Q_PROPERTY(QStringList repoDigests READ repoDigests WRITE setRepoDigests RESET resetRepoDigests NOTIFY repoDigestsChanged FINAL)
    Q_PROPERTY(QStringList repoTags READ repoTags WRITE setRepoTags RESET resetRepoTags NOTIFY repoTagsChanged FINAL)
    Q_PROPERTY(qlonglong sharedSize READ sharedSize WRITE setSharedSize RESET resetSharedSize NOTIFY sharedSizeChanged FINAL)
    Q_PROPERTY(qlonglong size READ size WRITE setSize RESET resetSize NOTIFY sizeChanged FINAL)
    Q_DOCKER_OBJECT_ID_NAME(id)
public:
    Q_INVOKABLE explicit Image(QObject *parent=nullptr);

    //!
    //! \brief containers
    //! \return
    //!
    int containers() const;
    void setContainers(int newContainers);
    void resetContainers();

    //!
    //! \brief created
    //! \return
    //!
    qlonglong created() const;
    void setCreated(qlonglong newCreated);
    void resetCreated();

    //!
    //! \brief id
    //! \return
    //!
    QString id() const;
    void setId(const QString &newId);
    void resetId();

    //!
    //! \brief labels
    //! \return
    //!
    QVariantHash labels() const;
    void setLabels(const QVariantHash &newLabels);
    void resetLabels();

    //!
    //! \brief parentId
    //! \return
    //!
    QString parentId() const;
    void setParentId(const QString &newParentId);
    void resetParentId();

    //!
    //! \brief repoDigests
    //! \return
    //!
    QStringList repoDigests() const;
    void setRepoDigests(const QStringList &newRepoDigests);
    void resetRepoDigests();

    //!
    //! \brief repoTags
    //! \return
    //!
    QStringList repoTags() const;
    void setRepoTags(const QStringList &newRepoTags);
    void resetRepoTags();

    //!
    //! \brief sharedSize
    //! \return
    //!
    qlonglong sharedSize() const;
    void setSharedSize(qlonglong newSharedSize);
    void resetSharedSize();

    //!
    //! \brief size
    //! \return
    //!
    qlonglong size() const;
    void setSize(qlonglong newSize);
    void resetSize();

signals:
    void containersChanged();

    void createdChanged();

    void idChanged();

    void labelsChanged();

    void parentIdChanged();

    void repoDigestsChanged();

    void repoTagsChanged();

    void sharedSizeChanged();

    void sizeChanged();

private:
    int _containers;
    qlonglong _created;
    QString _id;
    QVariantHash _labels;
    QString _parentId;
    QStringList _repoDigests;
    QStringList _repoTags;
    qlonglong _sharedSize;
    qlonglong _size;

};


}


