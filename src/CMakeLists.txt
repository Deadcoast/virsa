# src/CMakeLists.txt

add_subdirectory(configuration)
add_subdirectory(network)

if (${CMAKE_BUILD_TYPE} MATCHES "debug")
    add_subdirectory(gtest)
endif()
