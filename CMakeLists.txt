cmake_minimum_required(VERSION 3.13)

project("Adventure Game")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options("-fdiagnostics-absolute-paths")
    add_link_options("-fdiagnostics-absolute-paths")
endif()

add_subdirectory("src")