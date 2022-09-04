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
#include "src/network/ipv4/Socket.h"

namespace network
{

namespace IPv4
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
    ~UDPSocket();

protected:

    /**
     * Creates/connects the socket.
     * 
     * @return True if socket was created/connected successfully;
     *         False otherwise.
     */
    virtual bool start();

};

} // end namespace IPv4

} // end namespace network

#endif // UDP_SOCKET_H
