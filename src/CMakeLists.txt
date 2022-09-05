# src/CMakeLists.txt

# Source files for executable
set(SOURCES
    ${SOURCES}
    main.cpp)

# VIRSA executable
add_executable(${PROJECT_NAME} ${SOURCES})

if (${CMAKE_BUILD_TYPE} MATCHES "release")
    add_custom_command(TARGET ${PROJECT_NAME}
        COMMAND ${CMAKE_SOURCE_DIR}/src/updateBuildInfo.sh virsa -d ${CMAKE_SOURCE_DIR}/src/
        PRE_BUILD
        DEPENDS ${CMAKE_SOURCE_DIR}/src/updateBuildInfo.sh
        COMMENT "Updating build number for: ${PROJECT_NAME}"
    )
else()
    message(STATUS "Not release build...skipping updating build number")
endif()

add_subdirectory(network)
