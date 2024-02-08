CONFIG += console
CONFIG -= debug_and_release
CONFIG += testcase
QT += testlib

LC_ALL=en_US.UTF-8

INCLUDEPATH+=$$PWD/src

HEADERS += \
    $$PWD/qt_docker_unit_test_docker_cli_instance.h \
    $$PWD/qt_docker_util_test.h \
    $$PWD/qt_docker_util_test_main.h \
    $$PWD/qt_docker_unit_test_socket.h \

SOURCES += \
    $$PWD/qt_docker_util_test.cpp \
    $$PWD/qt_docker_util_test_main.cpp \
