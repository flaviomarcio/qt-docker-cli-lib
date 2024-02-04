#pragma once

#include "qt-docker-obj.h"

namespace QtDockerCli {

//!
//! \brief The Port class
//!
//! ref
//!     https://docs.docker.com/compose/compose-file/compose-file-v3/
//!     https://docs.docker.com/engine/reference/commandline/container_port/
//!     https://docs.docker.com/engine/swarm/ingress/
//! //!     https://docs.docker.com/engine/swarm/ingress/
class QT_DOCKER_CLI_LIB_EXPORT Port: public Object
{
    Q_OBJECT
    Q_PROPERTY(Protocol protocol READ protocol WRITE setProtocol RESET resetProtocol NOTIFY protocolChanged FINAL)
    Q_PROPERTY(PublishMode publishMode READ publishMode WRITE setPublishMode RESET resetPublishMode NOTIFY publishModeChanged FINAL)
    Q_PROPERTY(int targetPort READ targetPort WRITE setTargetPort RESET resetTargetPort NOTIFY targetPortChanged FINAL)
    Q_PROPERTY(int publishedPort READ publishedPort WRITE setPublishedPort RESET resetPublishedPort NOTIFY publishedPortChanged FINAL)
public:
    enum Protocol{
        tcp, udp
    };
    Q_ENUM(Protocol)
    enum PublishMode{
        host, ingress
    };
    Q_ENUM(PublishMode)

    explicit Port(QObject *parent=nullptr);
    Protocol protocol() const;
    void setProtocol(Protocol newProtocol);
    void resetProtocol();

    PublishMode publishMode() const;
    void setPublishMode(PublishMode newPublishMode);
    void resetPublishMode();

    int targetPort() const;
    void setTargetPort(int newTargetPort);
    void resetTargetPort();

    int publishedPort() const;
    void setPublishedPort(int newPublishedPort);
    void resetPublishedPort();

signals:
    void protocolChanged();

    void publishModeChanged();

    void targetPortChanged();

    void publishedPortChanged();

private:
    Protocol _protocol;
    PublishMode _publishMode;
    int _targetPort;
    int _publishedPort;
};


}
