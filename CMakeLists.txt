cmake_minimum_required(VERSION 3.14)

project(val CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

set(VAL_HOME ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(val)