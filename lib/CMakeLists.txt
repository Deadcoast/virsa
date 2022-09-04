# lib/CMakeLists.txt

# Only link GTest in debug configuration
if (${CMAKE_BUILD_TYPE} MATCHES "debug")
    add_subdirectory(googletest-release-1.12.1)
    enable_testing()
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
endif()
