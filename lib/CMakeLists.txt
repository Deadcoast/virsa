# lib/CMakeLists.txt

# Only link GTest in debug configuration
if (${CMAKE_BUILD_TYPE} MATCHES "debug")
    add_subdirectory(googletest-release-1.12.1)
    enable_testing()
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
endif()

# Boost linking
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "boost_1_80_0/")
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "boost/lib")
find_package(Boost 1.80.0 REQUIRED)

if (${Boost_FOUND})
    message(STATUS "Boost ${Boost_VERSION} has been found.")
    include_directories(${Boost_INCLUDE_DIR})
    add_compile_definitions(HAS_BOOST)
endif()
