# src/network/ipv4/CMakeLists.txt

set(HEADERS
    Socket.h
    UDPSocket.h
)

set(SOURCES
    Socket.cpp
    UDPSocket.cpp
)

target_sources(${PROJECT_NAME} PRIVATE ${HEADERS} ${SOURCES})
