cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(
    StaticLibrary
    VERSION 1.0.0
    DESCRIPTION "CMake Project Template"
    LANGUAGES C
)


set(CMAKE_C_STANDARD 17)


include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")

add_library(${PROJECT_NAME} STATIC ${SOURCES})