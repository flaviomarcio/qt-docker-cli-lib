#pragma once

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantList>
#include <QVariantHash>
#include "./qt_docker_util_test.h"
#include "./qt-docker-instance.h"

using namespace QtDockerCli;

namespace QtDockerCliTest {

class UT_DockerInstance : public ObjectTest
{
    Q_OBJECT
    Q_DOCKER_CLI_TEST(UT_DockerInstance)
public:
    Instance instance;

    Instance &configure(){
        auto &remoteHost=instance.remoteHost();
        remoteHost.setProtocol("http");
        remoteHost.setHostName("localhost");
        remoteHost.setBasePath("/v1.44");
        return instance;
    }

    Q_INVOKABLE void test_volumes()
    {
        configure().refresh();
        QVERIFY(!instance.networks().isEmpty());
        QVERIFY(!instance.images().isEmpty());
        QVERIFY(!instance.volumes().isEmpty());
        QVERIFY(!instance.nodes().isEmpty());
        QVERIFY(!instance.services().isEmpty());
        QVERIFY(!instance.containers().isEmpty());
    }

};

}
