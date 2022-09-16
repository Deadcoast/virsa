# VIRSA Root CMakeLists.txt

cmake_minimum_required(VERSION 3.20)

project(virsa VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Windows Libraries
if (WIN32)
    find_library(ws2_32_LIBRARY_PATH ws2_32)
    link_libraries(${ws2_32_LIBRARY_PATH})
endif()

# CMake modules
include(getSystemEndianness.cmake REQUIRED)
include(setupBoost.cmake REQUIRED)
include(setupGTest.cmake REQUIRED)
include(updateBuildNumber.cmake REQUIRED)

include_directories(src/)

# VIRSA executable
add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(config)
add_subdirectory(src)
