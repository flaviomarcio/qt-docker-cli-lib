QT += testlib

CONFIG += testcase
CONFIG += console
CONFIG += silent
CONFIG -= debug_and_release
QT -= gui

TEMPLATE = app
TARGET = QtDockerCliTests

QT_DOCKER_CLI_TEST=true
QMAKE_CXXFLAGS += -DQT_DOCKER_CLI_TEST=\\\"$$QT_DOCKER_CLI_TEST\\\"

include($$PWD/qt-docker-cli.pri)
include($$PWD/test/test.pri)
