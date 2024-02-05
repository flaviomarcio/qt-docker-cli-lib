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

class UT_Socket : public ObjectTest
{
    Q_OBJECT
    QT_DOCKER_CLI_TEST(UT_Socket)
public:
    Request request;

    Q_INVOKABLE void test_request()
    {
        request
            .call("http://localhost/v1.44/info")
            .wait()
            ;
        //curl --unix-socket /var/run/docker.sock http://localhost/v1.44/info

        // const auto envsIn=QVariantHash{{"user",QByteArray{getenv("USER")}}};

        // {
        //     auto parserTextIn="user=${user}";
        //     auto envsOutBytes=QString("user=%1").arg(QByteArray{getenv("USER")});

        //     auto envsInBytes=envs
        //                            .customEnvs(envsIn)
        //                            .parser(parserTextIn)
        //                            .toString();

        //     QCOMPARE_EQ(envsOutBytes, envsInBytes);
        // }
    }

};

}
