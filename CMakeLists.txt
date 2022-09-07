# VIRSA Root CMakeLists.txt

cmake_minimum_required(VERSION 3.20)

project(virsa VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(./)

# VIRSA executable
add_executable(${PROJECT_NAME} src/main.cpp)

# If building release, add custom command to increment build number
if (${CMAKE_BUILD_TYPE} MATCHES "release")
    add_compile_definitions(BUILD_TYPE_RELEASE)
    add_custom_command(TARGET ${PROJECT_NAME}
        PRE_BUILD
        COMMAND ${CMAKE_SOURCE_DIR}/src/updateBuildInfo.sh ${PROJECT_NAME} -d ${CMAKE_SOURCE_DIR}/src/
        DEPENDS ${CMAKE_SOURCE_DIR}/src/updateBuildInfo.sh
        COMMENT "Updating build number for: ${PROJECT_NAME}"
        )
else()
    enable_testing()
    add_compile_definitions(BUILD_TYPE_DEBUG)
    message(STATUS "Not release build...skipping updating build number")
endif()

# Shorthand function for adding gtests
function(add_gtest name source)
    if (${CMAKE_BUILD_TYPE} MATCHES "debug")
        add_executable(${name} ${source})
        target_link_libraries(${name} GTest::gtest_main)
        gtest_discover_tests(${name})
    endif()
endfunction()

add_subdirectory(lib)
add_subdirectory(src)
