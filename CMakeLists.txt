cmake_minimum_required(VERSION 3.5.2)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
project(kingdomino-ai)

set(SOURCES
    Source/Main.cpp

    Source/TileSet.h
    Source/TileSet.cpp
)

add_executable(kingdomino-ai ${SOURCES})

# assume a local SFML copy is here
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

target_link_libraries(kingdomino-ai PRIVATE sfml-system sfml-graphics sfml-network)