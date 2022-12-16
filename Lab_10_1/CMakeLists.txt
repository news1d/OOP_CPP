cmake_minimum_required(VERSION 3.23)
project(Lab_10_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_10_1 main.cpp classes.h)
target_link_libraries(Lab_10_1 stdc++fs)
