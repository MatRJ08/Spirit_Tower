cmake_minimum_required(VERSION 3.16)
project(Spirit_Tower)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lcurl")
set(SOURCE_FILES main.cpp)

add_executable(Spirit_Tower main.cpp Backtracking.h Backtracking.cpp lista.h lista.cpp Nodo.cpp Nodo.h A_star.cpp A_star.h)