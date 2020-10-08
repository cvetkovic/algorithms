cmake_minimum_required(VERSION 3.16)
project(testground)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

file(GLOB SOURCES main.cpp collections/*.hpp)

add_executable(testground ${SOURCES} tests/linked_list_tests.cpp)