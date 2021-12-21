cmake_minimum_required(VERSION 3.0)

project(serial_read_test)
SET(PROJECT_VERSION_MAJOR 0)
SET(PROJECT_VERSION_MINOR 1)

set(libs    
    pthread
    stdc++fs
)

#
#add_library(mylibs   
#)
#

add_executable(
    serial_read_test

    #src/ex01.cpp
    #src/ex02.cpp
    #src/ex03.cpp

    #src/readTest01.cpp
    #src/readTest02.cpp
    #src/readTest03.cpp
    src/readTest04.cpp

)

#enable_testing()
#add_subdirectory(tests)