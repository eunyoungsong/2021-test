#set(my_unit_test)

project(my_unit_test)
cmake_minimum_required(VERSION 3.5)
add_compile_options(-g -Wall -std=c++17)

link_directories(..)

add_executable(
    my_test
    my_stack_test.cpp
    my_queue_test.cpp
    my_queue_struct_test.cpp
    my_queue_class_test.cpp
    my_circular_queue_test.cpp
    ex_circular_queue_test.cpp
    my_deque_class_test.cpp
    my_deque_template_test.cpp
)

target_link_libraries(
    my_test
    my_libs
)

