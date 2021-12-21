cmake_minimum_required(VERSION 3.0)

set(name "unit_test")
project(unit_test)
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

add_library(
    my_libs
    src/my_stack.cpp
    src/my_queue_c.c
    src/my_queue_struct.c
    src/my_queue_class.cpp
    src/my_circular_queue.cpp
    src/ex_circular_queue.cpp
    src/my_deque_class.cpp
    src/my_deque_template.cpp
)

enable_testing()
add_subdirectory(tests)
