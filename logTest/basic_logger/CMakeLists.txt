cmake_minimum_required(VERSION 3.0)

project(basic_log_test)
SET(PROJECT_VERSION_MAJOR 0)
SET(PROJECT_VERSION_MINOR 1)

set(libs    
    stdc++fs
    boost_program_option
)

set(CMAKE_CXX_FLAGS "-lboost_log")
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

add_executable(
    log_test01
    src/log_test01.cpp
)

add_executable(
    log_test02
    src/log_test02.cpp
)

add_executable(
    log_test03
    src/log_test03.cpp
)

add_executable(
    log_test04
    src/log_test04.cpp
)

add_executable(
    log_test05
    src/log_test05.cpp
)

add_executable(
    log_test06
    src/log_test06.cpp
)

add_executable(
    log_test07
    src/log_test07.cpp
)

add_executable(
    log_test08
    src/log_test08/logger.h
    src/log_test08/logger.cpp
    src/log_test08/main.cpp
)