cmake_minimum_required(VERSION 3.1)

project(date_test)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(date_test
    ${CMAKE_CURRENT_SOURCE_DIR}/src/date.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
target_include_directories(date_test PUBLIC
    project
)
set_target_properties(date_test PROPERTIES
    CXX_STANDARD 14
)

target_sources(date_test PRIVATE
    ../googletest/googletest/src/gtest-all.cc
)
target_include_directories(date_test PRIVATE
    ../googletest/googletest
    ../googletest/googletest/include
)
target_link_libraries(date_test
    pthread
)
