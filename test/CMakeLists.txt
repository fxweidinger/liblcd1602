cmake_minimum_required(VERSION 3.13)
project(Test CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)
link_directories(${CMAKE_HOME_DIRECTORY}/lib)

add_executable(Test test.cpp)
target_link_libraries(Test pigpio
                    liblcd1602)