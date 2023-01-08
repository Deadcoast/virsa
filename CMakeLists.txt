# VIRSA Root CMakeLists.txt

cmake_minimum_required(VERSION 3.20)

include_directories(src/)

project(virsa)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Windows Libraries
if (WIN32)
    find_library(ws2_32_LIBRARY_PATH ws2_32)
    link_libraries(${ws2_32_LIBRARY_PATH})
endif()

# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/build/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/build/release")

# Build lib directory
add_subdirectory(lib)

# Add Boost library
set(Boost_ROOT "${CMAKE_CURRENT_LIST_DIR}/lib/boost_1_78_0")
set(Boost_INCLUDE_DIR "${Boost_ROOT}")
set(Boost_LIBRARY_DIR "${Boost_ROOT}/stage/lib")
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(Boost_USE_DEBUG_LIBS ON)
    set(Boost_USE_DEBUG_RUNTIME ON)
else()
    set(Boost_USE_RELEASE_LIBS ON)
    set(Boost_USE_RELEASE_RUNTIME ON)
endif()

include(cmake/setupBoost.cmake REQUIRED)

# Add GTest library
include(cmake/addGoogleTest.cmake REQUIRED)

# Project executable
add_executable(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC ./)

# Project directories
add_subdirectory(config)
add_subdirectory(src)

# Link project libraries
target_link_libraries(${PROJECT_NAME} PUBLIC NetworkUtils)
