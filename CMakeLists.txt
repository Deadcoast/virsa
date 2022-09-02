# VIRSA Root CMakeLists.txt

cmake_minimum_required(VERSION 3.20)

project(VIRSA VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# VIRSA executable
add_executable(${PROJECT_NAME} src/main.cpp)
