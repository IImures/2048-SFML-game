cmake_minimum_required(VERSION 3.25)
project(2048)

set(CMAKE_CXX_STANDARD 23)
set(BUILD_SHARED_LIBS FALSE)

add_executable(2048 main.cpp Board.h Board.cpp Block.h Block.cpp)

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(2048
        sfml-system
        sfml-window
        sfml-graphics
        )