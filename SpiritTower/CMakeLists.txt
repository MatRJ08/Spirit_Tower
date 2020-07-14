cmake_minimum_required(VERSION 3.16)
project(SpiritTower)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpiritTower src/server.cpp src/main.cpp src/server.h src/controller.h src/controller.cpp src/Specter.h src/Player.h src/Specter.cpp src/Player.cpp src/LinkedList.h src/LinkedList.cpp)

if(CYGWIN)
target_link_libraries(SpiritTower ws2_32)
endif()

if(MINGW)
    target_link_libraries(SpiritTower ws2_32)
endif()