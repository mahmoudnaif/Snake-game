cmake_minimum_required(VERSION 3.26)
project(hello_sfml)

set(CMAKE_CXX_STANDARD 17)

add_executable(hello_sfml main.cpp
        snakegame.h
        snakegame.cpp
        mysnake.cpp
        mysnake.h
        Update.cpp
        Apple.cpp
        Apple.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

INCLUDE_DIRECTORIES(C:/SFML/include)

target_link_libraries(hello_sfml sfml-system sfml-window sfml-graphics sfml-audio)
