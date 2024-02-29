cmake_minimum_required(VERSION 3.28)
project(aoc2023 CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_GENERATOR "Ninja")
add_compile_options(-pedantic -Wall -Wextra -stdlib=libstdc++)

#TARGET_ARCH=uname -m
execute_process(COMMAND "uname -m" OUTPUT_VARIABLE TARGET_ARCH OUTPUT_STRIP_TRAILING_WHITESPACE)

message("Target Architecture: ${CMAKE_SYSTEM_PROCESSOR}")
# Use GCC standard library from GCC 14.0.0
include_directories(BEFORE SYSTEM "/usr/local/include/c++/14.0.0")
if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_x64")
    include_directories(BEFORE SYSTEM
      "/usr/local/include/c++/14.0.0/x86_64-linux-gnu/")
else()
    include_directories(BEFORE SYSTEM
      "/usr/local/include/c++/14.0.0/aarch64-linux-gnu/")
endif()

add_subdirectory(day1)
