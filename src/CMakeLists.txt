# src/CMakeLists.txt

set(SOURCES
    main.cpp
    VIRSA.cpp
)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

add_subdirectory(configuration)
add_subdirectory(network)

if (${CMAKE_BUILD_TYPE} MATCHES "debug")
    add_subdirectory(gtest)
endif()
