cmake_minimum_required(VERSION 3.16)
project(Spirit_Tower)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lcurl")
set(SOURCE_FILES main.cpp)

add_executable(Spirit_Tower main.cpp path/Backtracking.h path/Backtracking.cpp path/lista.h path/lista.cpp path/Nodo.cpp path/Nodo.h path/A_star.cpp path/A_star.h genetico/Espectros.cpp genetico/Espectros.h genetico/Evolucionador.cpp genetico/Evolucionador.h Game.cpp Game.h Criaturas.cpp Criaturas.h)