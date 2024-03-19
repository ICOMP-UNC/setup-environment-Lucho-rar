#version minima requerida
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

#definicion del proyecto
project(
    FirstProject
    VERSION 1.0.0
    DESCRIPTION "CMake Project Template"
    LANGUAGES C
)

#standard C
set(CMAKE_C_STANDARD 17)

#include directories
include_directories(include)

#src
file(GLOB_RECURSE SOURCES "src/*.c")

#executable
add_executable(${PROJECT_NAME} ${SOURCES})

#libs
add_subdirectory(lib/libstat) # lib static
add_subdirectory(lib/libdyn) # lib dyn

target_include_directories(${PROJECT_NAME} PUBLIC lib/libstat/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/libdyn/include)

target_link_libraries(${PROJECT_NAME}
    StaticLibrary
    DynLibrary
)