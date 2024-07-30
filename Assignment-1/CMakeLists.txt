# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(Assignment1 C)

# Set the C standard
set(CMAKE_C_STANDARD 11)

# Add the executable target with source files
add_executable(Assignment1 
    src/hare-and-turtle.c 
    src/common.c
    )

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(Assignment1 PRIVATE ${CMAKE_SOURCE_DIR}/src)
