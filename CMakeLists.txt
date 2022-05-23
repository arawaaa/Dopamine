cmake_minimum_required(VERSION 3.16)

project(dopamine VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_MIN_VERSION "5.15.0")
set(KF5_MIN_VERSION "5.90")
find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)

set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH}  ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(CheckIncludeFiles)
include(KDEInstallDirs)
find_package(Qt5 REQUIRED COMPONENTS Gui Qml Quick Core)
find_package(KF5 REQUIRED Kirigami2 Prison DBusAddons)

set(CMAKE_AUTOMOC ON)

add_subdirectory(src)

#install(PROGRAMS org.forreddit.dopamine DESTINATION ${KDE_INSTALL_APPDIR})
install( TARGETS dopamine ${KDE_INSTALL_TARGETS_DEFAULT_ARGS} )
