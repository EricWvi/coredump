cmake_minimum_required(VERSION 3.20)
project(gdb_demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Debug build with symbols and no optimization
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

add_executable(gdb_demo main.cpp)
