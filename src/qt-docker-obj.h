#pragma once

#include <QString>
#include <QUuid>
#include <QUrl>
#include <QDateTime>
#include <QVariant>
#include <QVariantHash>
#include <QVariantList>
#include <QStringList>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QObject>
#include "../3rdparty/qstm/src/qstm_object_wrapper.h"
#include "qt-docker-global.h"

namespace QtDockerCli {
class ObjectPvt;

#define Q_DOCKER_OBJECT_ID_NAME(PROPERTY_NAME)\
public: \
QByteArray propertyIdName(){\
    static const auto __propertyIdName=QByteArray(#PROPERTY_NAME);\
    return __propertyIdName;\
}


//!
//! \brief The Object class
//!
class QT_DOCKER_CLI_LIB_EXPORT Object: public QStm::ObjectWrapper
{
    Q_OBJECT
    Q_PROPERTY(QUuid objectId READ objectId WRITE setObjectId RESET resetObjectId NOTIFY objectIdChanged FINAL)
public:
    //!
    //! \brief Object
    //! \param parent
    //!
    Q_INVOKABLE explicit Object(QObject *parent=nullptr);

    //!
    //! \brief propertyIdName
    //! \return
    //!
    Q_INVOKABLE virtual QByteArray propertyIdName(){
        return {};
    }

    //!
    //! \brief objectId
    //! \return
    //!
    virtual QUuid objectId() const;
    virtual void setObjectId(const QUuid &newId);
    virtual void resetObjectId();

signals:
    void objectIdChanged();
private:
    ObjectPvt *p=nullptr;
};


}
