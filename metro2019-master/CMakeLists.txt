cmake_minimum_required(VERSION 3.12)
project(metro2019_Working)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(metro2019_Working
        Area.cpp
        Area.h
        graph.cpp
        graph.h
        main.cpp
        Point.cpp
        Point.h
        Station.cpp
        Station.h
        stretch.cpp
        stretch.h)
