cmake_minimum_required(VERSION 3.20)
project(esercitazione10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

enable_testing()
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

set(SRC_cg gradiente_coniugato.cpp)
add_executable(test_gradiente ${SRC_cg})
target_link_libraries(test_gradiente Eigen3::Eigen)

add_test(NAME test_gradiente COMMAND test_gradiente)