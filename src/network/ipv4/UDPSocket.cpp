/**
 * Source code for UDP Socket.
 * 
 * @file UDPSocket.cpp
 */

// Network includes
#include "src/network/ipv4/UDPSocket.h"

network::IPv4::UDPSocket::UDPSocket(const char *address, uint16_t port) :
    Socket(address, port, SOCK_DGRAM)
{

}

network::IPv4::UDPSocket::~UDPSocket()
{

}

bool network::IPv4::UDPSocket::start()
{
    if (fileDescriptor == SOCKET_UNASSIGNED)
    {
        return false;
    }

    struct sockaddr_in socketInfo;
    socketInfo.sin_family = AF_INET;
    socketInfo.sin_port = htons(port);

    // Convert address to binary representation
    if (inet_pton(AF_INET, address, &socketInfo.sin_addr) <= 0)
    {
        fprintf(stderr, "Invalid address: %s:%hu\n", address, port);
        return false;
    }

    if (connect(fileDescriptor, reinterpret_cast<struct sockaddr *>(&socketInfo), sizeof(socketInfo)) < 0)
    {
        fprintf(stderr, "Failed to connect to %s:%hu\n", address, port);
        return false;
    }

    return true;
}
