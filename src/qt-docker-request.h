#pragma once

#include <QObject>
#include "qt-docker-global.h"

namespace QtDockerCli {
class RequestPvt;
//!
//! \brief The Request class
//!
class QT_DOCKER_CLI_LIB_EXPORT Request: public QObject
{
    Q_OBJECT
public:
    explicit Request(QObject *parent=nullptr);

    //!
    //! \brief clear
    //! \return
    //!
    Request &clear();

    //!
    //! \brief serverName
    //! \return
    //!
    QString &serverName() const;
    Request &serverName(const QString &newServerName);

    //!
    //! \brief call
    //! \param args
    //! \return
    //!
    Request &call(const QByteArray &args);

    //!
    //! \brief wait
    //! \return
    //!
    Request &wait();

    //!
    //! \brief responseBody
    //! \return
    //!
    QByteArray &responseBody() const;


private:
    RequestPvt *p=nullptr;
signals:
    void started();
    void connected();
    void sent(QByteArray args);
    void received(QByteArray body);
    void fail(QString message);
    void finished();
};

}
