cmake_minimum_required(VERSION 3.1)

project(port_test)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(port_test
    	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    	${CMAKE_CURRENT_SOURCE_DIR}/src/port.cpp
    	${CMAKE_CURRENT_SOURCE_DIR}/src/vintage_port.cpp
)
target_include_directories(port_test PUBLIC
    project
)
set_target_properties(port_test PROPERTIES
    CXX_STANDARD 14
)

target_sources(port_test PRIVATE
    ../googletest/googletest/src/gtest-all.cc
)
target_include_directories(port_test PRIVATE
    ../googletest/googletest
    ../googletest/googletest/include
)
target_link_libraries(port_test
    pthread
)
