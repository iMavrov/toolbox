cmake_minimum_required(VERSION 3.8)

project(toolbox VERSION 0.03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(core)
add_subdirectory(unit)
add_subdirectory(examples)
