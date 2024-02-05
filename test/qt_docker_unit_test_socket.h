#pragma once

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantList>
#include <QVariantHash>
#include "./qt_docker_util_test.h"

// using namespace QStm;

namespace QtDockerCliTest {

class UT_Socket : public ObjectTest
{
    Q_OBJECT
    QT_DOCKER_CLI_TEST(UT_Socket)
public:
    Q_INVOKABLE void test_replaceSystemEnvs()
    {
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
