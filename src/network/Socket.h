/**
 * Header file for base network IPv4 Socket.
 * 
 * @file Socket.h
 */

#ifndef SOCKET_H
#define SOCKET_H

// System includes
#include <cstdint>
#include <cstdio>

#ifdef _WIN32
// Network includes
#include <WinSock2.h>
#include <Windows.h>
#include <inaddr.h>
#else
// Network includes
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#endif // _WIN32

#ifdef _WIN32
typedef int32_t socklen_t;
typedef int32_t ssize_t;
constexpr uint32_t INET_ADDRSTRLEN = 16;
#endif // _WIN32

namespace network
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
     * Indicates a read/write error for socket.
     */
    static constexpr int32_t READ_WRITE_FAILURE = -1;

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
     * File descriptor for the socket.
     */
    int32_t fileDescriptor;

    /**
     * Destination information of socket.
     */
    struct sockaddr_in destination;

    /**
     * Flag whether socket is connected to destination.
     */
    bool socketConnected;

}; // Socket

} // end namespace network

#endif // SOCKET_H
