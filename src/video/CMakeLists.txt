# src/video/CMakeLists.txt

# Common source files
set(SOURCES

)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

if (WIN32)
    add_subdirectory(win)
else()
    add_subdirectory(unix)
endif()
