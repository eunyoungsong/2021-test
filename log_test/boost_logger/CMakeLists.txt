cmake_minimum_required(VERSION 3.0)

project(boost_log_test)
SET(PROJECT_VERSION_MAJOR 0)
SET(PROJECT_VERSION_MINOR 1)

set(libs    
    stdc++fs
    pthread
    boost_log
)

set(CMAKE_CXX_FLAGS "-lboost_log")
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})


add_executable(
    boost_log01
    src/boost_log01.cpp
)
TARGET_LINK_LIBRARIES(boost_log01 ${Boost_LIBRARIES})

add_executable(
    boost_log02
    src/boost_log02.cpp
)
TARGET_LINK_LIBRARIES(boost_log02 ${Boost_LIBRARIES})

add_executable(
    boost_log03
    src/boost_log03.cpp
)
TARGET_LINK_LIBRARIES(boost_log03 ${Boost_LIBRARIES})

add_executable(
    boost_log04
    src/boost_log04.cpp
)
TARGET_LINK_LIBRARIES(boost_log04 ${Boost_LIBRARIES})

add_executable(
    boost_log05
    src/boost_log05.cpp
)
TARGET_LINK_LIBRARIES(boost_log05 ${Boost_LIBRARIES})

add_executable(
    boost_log06
    src/boost_log06.cpp
)
TARGET_LINK_LIBRARIES(boost_log06 ${Boost_LIBRARIES})

add_executable(
    boost_log10
    src/boost_log10.cpp
)
TARGET_LINK_LIBRARIES(boost_log10 ${Boost_LIBRARIES})