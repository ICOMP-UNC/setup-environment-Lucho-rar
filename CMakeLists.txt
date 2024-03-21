#version minima requerida
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

#definicion del proyecto
project(
    FirstProject
    VERSION 1.0.0
    DESCRIPTION "CMake Project Template"
    LANGUAGES C
)

include(CTest)
#standard C
set(CMAKE_C_STANDARD 17)

#include directories
include_directories(include)



#unity 

include(FetchContent)

set(UNITY_GIT_URL https://github.com/ThrowTheSwitch/Unity.git)
set(FETCHCONTENT_QUIET OFF)


FetchContent_Declare(
        Unity
        GIT_REPOSITORY ${UNITY_GIT_URL}
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
        UPDATE_COMMAND "" # Disable the update command
)

FetchContent_MakeAvailable(Unity)

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


if(RUN_TESTS EQUAL 1 OR RUN_COVERAGE EQUAL 1)
    add_subdirectory(test)
endif ()