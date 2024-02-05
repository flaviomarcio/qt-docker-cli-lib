#include "qt_docker_util_test_main.h"
#include <QTest>

//tests
#include "./qt_docker_unit_test_socket.h"


#define Q_DOCKER_CLI_RUNNER(CLASS){CLASS var; var.execute();}

namespace QtDockerCliTest{

void TestMain::execute()
{
    Q_DOCKER_CLI_RUNNER(UT_Socket);
}

}
QTEST_MAIN(QtDockerCliTest::TestMain)
#include "moc_qt_docker_util_test_main.cpp"


