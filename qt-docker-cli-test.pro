QT += testlib

CONFIG += testcase
CONFIG += console
CONFIG += silent
CONFIG -= debug_and_release
QT -= gui

TEMPLATE = app
TARGET = QtRequestClientTests

INCLUDEPATH+=$$PWD/../src
#INCLUDEPATH+=$$PWD/../src/private

qt_reforce_request_util_test_MODE=true
QMAKE_CXXFLAGS += -Dqt_reforce_request_util_test_MODE=\\\"$$qt_reforce_request_util_test_MODE\\\"

include($$PWD/test/test.pri)


