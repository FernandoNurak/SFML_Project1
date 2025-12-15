cmake_minimum_required(VERSION 3.26)
project(sfml_app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(sfml_app
    src/main.cpp
)

target_link_libraries(sfml_app
    PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)
