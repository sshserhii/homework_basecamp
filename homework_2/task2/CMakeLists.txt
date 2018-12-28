cmake_minimum_required(VERSION 3.5)
project(move_test)

set(CMAKE_BUILD_TYPE Release)
include_directories(include)
add_compile_options(-std=c++11)

file(GLOB SOURCES "src/*.cpp")
add_library(test_m SHARED ${SOURCES})
install(TARGETS test_m DESTINATION /usr/lib)

set(PROJECT_LINK_LIBS libtest_m.so)
link_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if(EXISTS "/usr/lib/${PROJECT_LINK_LIBS}")
add_executable(main src/main.cpp)
target_link_libraries(main ${PROJECT_LINK_LIBS})
endif() 	
