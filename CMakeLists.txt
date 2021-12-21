cmake_minimum_required(VERSION 3.0)

project(log-test)
SET(PROJECT_VERSION_MAJOR 0)
SET(PROJECT_VERSION_MINOR 1)

set(libs    
    pthread
    stdc++fs
    boost_utility
    boost_log
)


SET(CMAKE_CXX_FLAGS "-lboost_program_options -lboost_log")
FIND_PACKAGE( Boost COMPONENTS program_options log REQUIRED )
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

add_executable(
    log-test
    
    src/log_test_01.cpp
    src/log_test_02.cpp
    src/log_test_03.cpp
    src/log_test_04.cpp
    src/log_test_05.cpp
    src/log_test_06.cpp
    src/log_test_07.cpp  
)
TARGET_LINK_LIBRARIES(logd-test01 ${Boost_LIBRARIES})