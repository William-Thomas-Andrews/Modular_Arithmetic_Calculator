cmake_minimum_required(VERSION 4.1.0)

project(MOD)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SRC_FILES
    src/*.cpp
)

add_executable(MOD 
    test/test.cpp
    ${SRC_FILES}
)

target_include_directories(MOD
    PUBLIC ${CMAKE_SOURCE_DIR}/src
    PUBLIC ${CMAKE_SOURCE_DIR}/src/utils
    PUBLIC ${CMAKE_SOURCE_DIR}/src/graph
    PUBLIC ${CMAKE_SOURCE_DIR}/src/data
)

target_include_directories(MOD PRIVATE include)