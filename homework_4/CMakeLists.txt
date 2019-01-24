cmake_minimum_required(VERSION 3.1)

project(String_test)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(String_test
    	${CMAKE_CURRENT_SOURCE_DIR}/src/string_m.cpp  
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
target_include_directories(String_test PUBLIC
    project
)
set_target_properties(String_test PROPERTIES
    CXX_STANDARD 14
)

target_sources(String_test PRIVATE
    ../googletest/googletest/src/gtest-all.cc
)
target_include_directories(String_test PRIVATE
    ../googletest/googletest
    ../googletest/googletest/include
)
target_link_libraries(String_test
    pthread
)
