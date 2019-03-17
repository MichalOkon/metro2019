cmake_minimum_required(VERSION 3.13)
project(metro2019)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(metro2019
    include/Point.h
    include/Station.h
    src/Point.cpp
    src/Station.cpp
    main.cpp)
