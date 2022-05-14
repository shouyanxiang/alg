cmake_minimum_required(VERSION 3.0)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode leetcode.cpp)
target_include_directories(leetcode PRIVATE leetcode.h)