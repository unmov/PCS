cmake_minimum_required(VERSION 3.20)
project(esercitazione9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

enable_testing()

set(SRC_graph test_algoritmi.cpp)
add_executable(test_algoritmi ${SRC_graph})

add_test(NAME test_algoritmi COMMAND test_algoritmi)