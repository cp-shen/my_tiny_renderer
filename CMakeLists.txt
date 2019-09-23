# cmake file for project root

cmake_minimum_required(VERSION 3.13)
project(MyTinyRenderer)

set(CMAKE_CXX_STANDARD 14)

option(BUILD_TESTS "build tests or not" ON)
option(DEBUG "build debug symbols or not" OFF)

if(DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_subdirectory(${MyTinyRenderer_SOURCE_DIR}/src)

if(BUILD_TESTS)
    add_subdirectory(${MyTinyRenderer_SOURCE_DIR}/tests)
endif()
