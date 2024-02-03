#pragma once

#include <QtCore/qglobal.h>

#if defined(QTDOCKERCLILIB_LIBRARY)
#define QT_DOCKER_CLI_LIB_EXPORT Q_DECL_EXPORT
#else
#define QT_DOCKER_CLI_LIB_EXPORT Q_DECL_IMPORT
#endif
