/**
 * Header file for base network IPv4 Socket.
 * 
 * @file Socket.h
 */

#ifndef SOCKET_H
#define SOCKET_H

// System includes
#include <cstdint>

#ifdef _WIN32
#error Socket library not currently supported on windows.
#else
// Network includes
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#endif // _WIN32

namespace network
{

namespace IPv4
{

/**
 * Represents an IPv4 socket for network communication.
 */
class Socket
{

public:

    /**
     * Indicates that no socket is created (no file descriptor has
     * been assigned by the OS).
     */
    static constexpr int32_t SOCKET_UNASSIGNED = -1;

    /**
     * Constructor for Socket.
     * 
     * @param address Destination IPv4 address of socket.
     * @param port Destination port of socket.
     */
    Socket(const char *address, uint16_t port, int32_t protocol);

    /**
     * Destructor for Socket.
     */
    ~Socket();

    /**
     * Closes the socket.
     */
    bool disconnect();

    /**
     * Checks if socket is connected.
     * 
     * @return True if socket is currently connected; False otherwise.
     */
    bool isConnected();

    /**
     * Sends data to destination through network.
     * 
     * @param data Data to send.
     * @param numBytes Size of data (in bytes).
     * 
     * @return Number of bytes successfully sent.
     */
    ssize_t sendData(void *data, size_t numBytes);

    /**
     * Reads data from network.
     * 
     * @param buffer Buffer to store data being read.
     * @param numBytes Number of bytes to read.
     * 
     * @return Number of bytes successfully read.
     */
    ssize_t readData(void *buffer, size_t numBytes);

    /**
     * Gets a socket option.
     * 
     * @param option Option to get.
     * @param optionValue Buffer to store value of specified option.
     * @param optionSize Size of option value buffer (in bytes).
     * 
     * @return Value of socket error state (zero is operation is successfull).
     */
    int32_t getSocketOption(int32_t option, void *optionValue, socklen_t optionSize);

    /**
     * Sets a socket option.
     * 
     * @param option Option being set.
     * @param optionValue Value of option being set.
     * @param optionSize Size of option value (in bytes).
     * 
     * @return Value of socket error state (zero is operation is successfull).
     */
    int32_t setSocketOption(int32_t option, void *optionValue, socklen_t optionSize);

    /**
     * Gets error state of socket.
     * 
     * @return Current error state of socket.
     */
    int32_t getErrorState();

protected:

    /**
     * Connects the socket to the destination.
     * 
     * @return True if socket successfully connected; False otherwise.
     */
    virtual bool start() = 0;

    /**
     * File descriptor for the socket.
     */
    int32_t fileDescriptor;

    /**
     * String representation of IPv4 address for socket
     * destination.
     */
    const char *address;

    /**
     * Destination port of socket.
     */
    uint16_t port;

    /**
     * Flag whether socket is connected to destination.
     */
    bool socketConnected;

}; // Socket

} // end namespace IPv4

} // end namespace network

#endif // SOCKET_H
