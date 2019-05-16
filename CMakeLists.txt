cmake_minimum_required(VERSION 3.13)
project(metro2019)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)


add_executable(metro2019
        include/Area.h
        include/Display.h
        include/Graph.h
        include/Graphics.h
        include/Point.h
        include/Station.h
        include/Stretch.h
        include/Test.h
        src/Area.cpp
        src/Display.cpp
        src/Graph.cpp
        src/Graphics.cpp
        src/main.cpp
        src/Point.cpp
        src/Station.cpp
        src/Stretch.cpp
        src/test.cpp
        )
