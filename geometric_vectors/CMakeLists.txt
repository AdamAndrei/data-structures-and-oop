cmake_minimum_required(VERSION 3.20)
project(geometric_vectors)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Automatically collect all .cpp files from src/ subdirectories
file(GLOB_RECURSE SOURCES
    src/domain/*.cpp
    src/services/*.cpp
)

add_executable(geometric_vectors src/main.cpp ${SOURCES})

target_include_directories(geometric_vectors
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

# SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(geometric_vectors
    sfml-graphics
    sfml-window
    sfml-system
)