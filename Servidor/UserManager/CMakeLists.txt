cmake_minimum_required(VERSION 3.9)
project(UserManager)

set(CMAKE_CXX_STANDARD 11)


include_directories(pugixml-1.9)
include_directories(../MySQLConnector)
include_directories(../HashFunct)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Xml REQUIRED)

add_executable(UserManager ../MySQLConnector/MySQLConnector.cpp
        ../MySQLConnector/MySQLConnector.h
        ../HashFunct/HashClass.cpp ../HashFunct/HashClass.h
        main.cpp UserManager.cpp UserManager.h)

target_link_libraries(UserManager Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Sql Qt5::Xml)

