cmake_minimum_required(VERSION 3.8)

project(toolbox VERSION 0.01)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(toolbox src/bla.cpp)
