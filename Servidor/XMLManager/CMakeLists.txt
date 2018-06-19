cmake_minimum_required(VERSION 3.9)
project(XMLManager)

set(CMAKE_CXX_STANDARD 11)

include_directories(pugixml-1.9)
include_directories(../MySQLConnector)
include_directories(../DataManager)
include_directories(../HashFunct)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Xml REQUIRED)


add_executable(XMLManager
        pugiconfig.hpp
        pugixml.hpp
        pugixml.cpp
        mainServer.cpp
        mainServer.h
        ../MySQLConnector/MySQLConnector.cpp ../MySQLConnector/MySQLConnector.h
        ../DataManager/DataManager.cpp ../DataManager/DataManager.h
        ../HashFunct/HashClass.cpp ../HashFunct/HashClass.h
        main.cpp XMLManager.cpp XMLManager.h XMLParts.cpp XMLParts.h)

target_link_libraries(XMLManager Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Sql Qt5::Xml)
