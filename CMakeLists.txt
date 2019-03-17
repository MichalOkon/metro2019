cmake_minimum_required(VERSION 3.13)
project(metro)


set(CMAKE_CXX_STANDARD 14)

add_executable(metro main.cpp)

include_directories(.)
include_directories( ${MY_SOURCE_DIR}/src )
include_directories( ./include )