cmake_minimum_required(VERSION 3.5)
project (golf)

set(CMAKE_BUILD_TYPE Release)
add_compile_options(-std=c++11)

add_executable(golf_test gold.cpp) 
