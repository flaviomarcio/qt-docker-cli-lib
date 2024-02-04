TARGET = QtDockerCli
TEMPLATE = lib

CONFIG += silent

include($$PWD/3rdparty/qtrequestclient/qtrequestclient.pri)
include($$PWD/qt-docker-cli.pri)
