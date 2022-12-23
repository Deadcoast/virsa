# VIRSA Root CMakeLists.txt

cmake_minimum_required(VERSION 3.20)

include_directories(src/)

project(virsa)
add_executable(${PROJECT_NAME})

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Windows Libraries
if (WIN32)
    find_library(ws2_32_LIBRARY_PATH ws2_32)
    link_libraries(${ws2_32_LIBRARY_PATH})
endif()

# Build lib directory
add_subdirectory(lib)

# Add Boost library
set(Boost_ROOT "${CMAKE_CURRENT_LIST_DIR}/lib/boost_1_78_0")
set(Boost_INCLUDE_DIR "${Boost_ROOT}")
set(Boost_LIBRARY_DIR "${Boost_ROOT}/stage/lib")
include(cmake/setupBoost.cmake REQUIRED)

# Add GTest library
include(cmake/addGoogleTest.cmake REQUIRED)

# Project directories
add_subdirectory(config)
add_subdirectory(src)

# Link project libraries
target_link_libraries(${PROJECT_NAME} PUBLIC NetworkUtils)
