# addGTest.cmake
#
# Finds, includes, and links GoogleTest. Adds helper function for adding GTests

# Only link GTest in debug configuration
if (${CMAKE_BUILD_TYPE} MATCHES "debug")
    message(STATUS "Setting up GTest")
    enable_testing()
    add_subdirectory(lib/googletest-release-1.12.1)
    include_directories(lib/googletest-release-1.12.1/googletest/include)
    include_directories(lib/googletest-release-1.12.1/googlemock/include)
    link_libraries(gtest gtest_main)
endif()

function(add_gtest name testSource)
    if ("${CMAKE_BUILD_TYPE}" MATCHES "debug")
        add_executable(${name} ${testSource})
        gtest_discover_tests(${name})

        foreach(CURRENT_ARG RANGE 2 ${ARGC})
            list(APPEND TEST_SOURCES ${ARGV${CURRENT_ARG}})
            message(STATUS "Added ${ARGV${CURRENT_ARG}}")
        endforeach()

        target_sources(${name} PRIVATE ${TEST_SOURCES})
    endif()
endfunction()
