cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME "date_test")
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} 
${CMAKE_CURRENT_SOURCE_DIR}/src/date.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread -std=c++11)
