/**
 * Source code for UDP Socket.
 * 
 * @file UDPSocket.cpp
 */

// Network includes
#include "network/UDPSocket.h"

network::UDPSocket::UDPSocket(const char *address, uint16_t port) :
    Socket(address, port, SOCK_DGRAM)
{

}

network::UDPSocket::~UDPSocket()
{

}
