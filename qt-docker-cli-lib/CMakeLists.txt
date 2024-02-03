cmake_minimum_required(VERSION 3.14)

project(qt-docker-cli-lib LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)

add_library(qt-docker-cli-lib SHARED
  qt-docker-cli-lib_global.h
  qt-docker-cli-lib.cpp
  qt-docker-cli-lib.h
  qt-docker-obj-image.cpp
  qt-docker-obj-image.h
  qt-docker-obj-stack.cpp
  qt-docker-obj-stack.h
  qt-docker-obj-service.cpp
  qt-docker-obj-service.h
  qt-docker-obj-container.cpp
  qt-docker-obj-container.h
  qt-docker-obj-port.cpp
  qt-docker-obj-port.h
  qt-docker-obj-volume.cpp
  qt-docker-obj-volume.h
  qt-docker-obj-network.cpp
  qt-docker-obj-network.h
  qt-docker-obj-deploy.cpp
  qt-docker-obj-deploy.h
  qt-docker-obj-entrypoint.cpp
  qt-docker-obj-entrypoint.h
  qt-docker-obj-command.cpp
  qt-docker-obj-command.h
  qt-docker-obj-environment.cpp
  qt-docker-obj-environment.h
)

target_link_libraries(qt-docker-cli-lib PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(qt-docker-cli-lib PRIVATE Qt${QT_VERSION_MAJOR}::Network)
target_compile_definitions(qt-docker-cli-lib PRIVATE QTDOCKERCLILIB_LIBRARY)
