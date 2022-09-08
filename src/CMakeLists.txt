# src/CMakeLists.txt

set(HEADERS
    VIRSA.h
)

set(SOURCES
    VIRSA.cpp
)

target_sources(${PROJECT_NAME} PRIVATE ${HEADERS} ${SOURCES})

add_subdirectory(configuration)
add_subdirectory(network)

if (${CMAKE_BUILD_TYPE} MATCHES "debug")
    add_subdirectory(gtest)
endif()
