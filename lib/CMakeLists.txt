# lib/CMakeLists.txt

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    add_subdirectory(googletest)
endif()
