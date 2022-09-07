# src/configuration/CMakeLists.txt

set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_SOURCE_DIR})

set(SOURCES
    ${SOURCES}
    ConfigurationManager.cpp)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})
