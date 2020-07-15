cmake_minimum_required(VERSION 3.16)
project(SpiritTower)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpiritTower src/server.cpp src/main.cpp src/server.h src/Criaturas.cpp src/Game.cpp src/Game.h src/Criaturas.h src/genetico/Espectros.cpp src/genetico/Espectros.h src/genetico/Evolucionador.cpp src/genetico/Evolucionador.h src/path/A_star.cpp src/path/A_star.h src/path/Backtracking.cpp src/path/Backtracking.h src/path/lista.cpp src/path/lista.h src/path/Nodo.cpp src/path/Nodo.h)
target_link_libraries(SpiritTower ws2_32)