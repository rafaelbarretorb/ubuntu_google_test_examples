cmake_minimum_required(VERSION 3.12)

project(gtest_example)
SET(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

include_directories(
  include
)

add_library(square_root_lib src/square_root.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main square_root_lib)
 
add_executable(runTests test/tests.cpp)

target_link_libraries(runTests GTest::GTest GTest::Main square_root_lib pthread)
