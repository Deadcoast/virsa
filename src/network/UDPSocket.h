/**
 * Header file for UDP Socket.
 * 
 * @file UDPSocket.h
 */

#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

// System includes
#include <cstdint>
#include <cstdio>

// Network includes
#include "network/Socket.h"

namespace network
{

/**
 * Represents a UDP Unicast socket.
 */
class UDPSocket : public Socket
{

public:

    /**
     * Constructor for UDP Socket.
     * 
     * @param address IPv4 address of socket destination.
     * @param port Port of socket destination.
     */
    UDPSocket(const char *address, uint16_t port);

    /**
     * Destructor for UDP Socket.
     */
    virtual ~UDPSocket();

};

} // end namespace network

#endif // UDP_SOCKET_H
