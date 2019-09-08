cmake_minimum_required(VERSION 3.14)
project(atcoder)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D__DEBUG")
set(CMAKE_BUILD_TYPE Debug)

add_executable(A src/AtCoder/ABC140/A.cpp)
