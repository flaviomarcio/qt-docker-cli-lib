QTREFORCE_DOCKER_CLI=true
DEFINES+=QTREFORCE_DOCKER_CLI

QT+=core network
QT-=gui

include($$PWD/src/src.pri)

INCLUDEPATH += $$PWD/includes

HEADERS+= \
    $$PWD/includes/QtDockerCli
