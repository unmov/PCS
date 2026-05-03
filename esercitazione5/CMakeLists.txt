cmake_minimum_required(VERSION 3.20)
project(esercitazione5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

enable_testing()

set(SRC_measure_sorts2 timecounter.cpp measure_sorts2.cpp)
add_executable(measure_sorts2 ${SRC_measure_sorts2})

# Creo i target per gli eseguibili che effettueranno i test unitari
add_executable(test_numbers test_numbers.cpp)
add_test(NAME test_numeri COMMAND test_numbers)

add_executable(test_strings test_strings.cpp)
add_test(NAME test_stringhe COMMAND test_strings)