cmake_minimum_required(VERSION 3.5)
project(directory_test)


set(CMAKE_BUILD_TYPE Release)
include_directories(include)
add_compile_options(-std=c++11)

file(GLOB SOURCES "src/*.cpp")
add_library(tnt SHARED ${SOURCES})
install(TARGETS tnt DESTINATION /usr/lib)

set(PROJECT_LINK_LIBS libtnt.so)
link_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if(EXISTS "/usr/lib/${PROJECT_LINK_LIBS}")
add_executable(main src/main.cpp)
target_link_libraries(main ${PROJECT_LINK_LIBS})
endif() 
