cmake_minimum_required(VERSION 3.12)

project(gmock_example)
SET(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)
find_package(GMock REQUIRED)
 
# Link runTests with what we want to test and the GMock
add_executable(runTests test.cpp)
target_link_libraries(runTests GMock::Main GMock::GMock pthread)
