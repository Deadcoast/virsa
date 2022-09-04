# src/CMakeLists.txt

# Source files for executable
set(SOURCES
    ${SOURCES}
    main.cpp)

# VIRSA executable
add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(network)
