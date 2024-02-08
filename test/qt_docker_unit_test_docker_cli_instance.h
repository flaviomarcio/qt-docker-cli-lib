#pragma once

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantList>
#include <QVariantHash>
#include "./qt_docker_util_test.h"
#include "./qt-docker-request.h"

using namespace QtDockerCli;

namespace QtDockerCliTest {

class UT_DockerInstance : public ObjectTest
{
    Q_OBJECT
    QT_DOCKER_CLI_TEST(UT_DockerInstance)
public:
    Request request;

    Q_INVOKABLE void test_request()
    {

    }

};

}
