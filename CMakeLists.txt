cmake_minimum_required(VERSION 3.0.0)
project(test_20240105 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_BUILD_TYPE "Debug")
set(EXECUTABLE_OUTPUT_PATH "../bin/")


add_executable(test_20240105 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
