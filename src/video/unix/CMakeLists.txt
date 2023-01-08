# src/video/unix/CMakeLists.txt

set(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/VideoCapturer.cpp
)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
