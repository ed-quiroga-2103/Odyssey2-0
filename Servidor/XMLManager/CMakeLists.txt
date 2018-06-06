cmake_minimum_required(VERSION 3.9)
project(XMLManager)

set(CMAKE_CXX_STANDARD 11)

include_directories(pugixml-1.9)

add_executable(XMLManager
        pugiconfig.hpp
        pugixml.hpp
        pugixml.cpp
        main.cpp XMLManager.cpp XMLManager.h)