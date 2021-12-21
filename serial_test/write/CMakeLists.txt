cmake_minimum_required(VERSION 3.0)

project(serial_write_test)
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
    serial_write_test

    #src/ex01.cpp

    #src/write01.cpp
    #src/write02.cpp
    #src/write03_01.cpp
    #src/write03_02.cpp
    #src/write03_03.cpp
    #src/write03_04.cpp
    src/write03.cpp

)

#enable_testing()
#add_subdirectory(tests)