#include "qt_docker_util_test_main.h"
#include <QTest>

//tests
#include "./qt_docker_unit_test_socket.h"
#include "./qt_docker_unit_test_docker_cli_instance.h"


#define Q_DOCKER_CLI_RUNNER(CLASS){CLASS var; var.execute();}

namespace QtDockerCliTest{

void TestMain::execute()
{
    Q_DOCKER_CLI_RUNNER(UT_Socket);
    Q_DOCKER_CLI_RUNNER(UT_DockerInstance);
}

}
QTEST_MAIN(QtDockerCliTest::TestMain)
#include "moc_qt_docker_util_test_main.cpp"


