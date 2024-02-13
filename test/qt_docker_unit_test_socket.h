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
    Q_DOCKER_CLI_TEST(UT_Socket)
public:
    Request request;

    Q_INVOKABLE void test_request()
    {
        auto &response=request
                             .protocol("http")
                             .hostName("localhost")
                             .basePath("/v1.44")
                             .path("/info")
                             .call()
                             .wait()
                             .response();
        QVERIFY2(response, "fail on request");
        QVERIFY2(response.isOK(), "fail on request");
        QVERIFY2(!response.body().isEmpty(),"Invalid response body");

        auto v=response.asVariant();
        QVERIFY2(v.isValid(),"Invalid response body"+response.body());
    }

};

}
