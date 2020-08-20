cmake_minimum_required(VERSION 3.13)
project(liblcd1602)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
add_library(liblcd1602 SHARED ${SOURCE_FILES})
