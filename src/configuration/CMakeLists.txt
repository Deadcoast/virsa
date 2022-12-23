# src/configuration/CMakeLists.txt

set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_SOURCE_DIR})

set(SOURCES
    ConfigurationManager.cpp
)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    add_subdirectory(gtest)
endif()
