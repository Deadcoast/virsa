# updateBuildNumber.cmake
#
# Sets up command for updating build number in release configurations

# If building release, add custom command to increment build number
if (${CMAKE_BUILD_TYPE} MATCHES "release")
    add_compile_definitions(BUILD_TYPE_RELEASE)
    add_custom_command(TARGET ${PROJECT_NAME}
        PRE_BUILD
        COMMAND ${CMAKE_SOURCE_DIR}/src/updateBuildInfo.sh ${PROJECT_NAME} -d ${CMAKE_SOURCE_DIR}/src/
        DEPENDS ${CMAKE_SOURCE_DIR}/src/updateBuildInfo.sh
        COMMENT "Updating build number for: ${PROJECT_NAME}"
        )
else()
    add_compile_definitions(BUILD_TYPE_DEBUG)
    message(STATUS "Not release build...skipping updating build number")
endif()
