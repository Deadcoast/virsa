/**
 * Source code for IPv4 Socket.
 * 
 * @file Socket.cpp
 */

// Network includes
#include "network/Socket.h"

network::Socket::Socket(const char *address, uint16_t port, int32_t protocol) :
    fileDescriptor(SOCKET_UNASSIGNED),
    socketConnected(false)
{
    // Clear residual data from destination socket
    memset(&destination, 0x00, sizeof(destination));

    if (inet_addr(address) == -1)
    {
        fprintf(stderr, "Socket: Invalid IPv4 %s\n", address);
        return;
    }

    destination.sin_family = AF_INET;
    destination.sin_addr.S_un.S_addr = inet_addr(address);
    destination.sin_port = port;

    fileDescriptor = socket(AF_INET, protocol, IPPROTO_UDP);
    if (fileDescriptor == SOCKET_UNASSIGNED)
    {
        fprintf(stderr, "Socket:  Failed to create socket %s:%hu\n", address, port);
        return;
    }
    else
    {
        socketConnected = true;
    }
}

network::Socket::~Socket()
{
    if (fileDescriptor != SOCKET_UNASSIGNED)
    {
#ifdef _WIN32
        closesocket(fileDescriptor);
#else
        close(fileDescriptor);
#endif // _WIN32
        fileDescriptor = SOCKET_UNASSIGNED;
    }
}

bool network::Socket::isConnected()
{
    return socketConnected;
}

ssize_t network::Socket::sendData(void *data, size_t numBytes)
{
    // do nothing if data does not exist
    if (data == NULL)
    {
        return READ_WRITE_FAILURE;
    }

    // ensure socket is open and connected
    if ((!socketConnected) || (fileDescriptor == SOCKET_UNASSIGNED))
    {
        return READ_WRITE_FAILURE;
    }

    return sendto(fileDescriptor, reinterpret_cast<char *>(data), numBytes, 0, reinterpret_cast<sockaddr *>(&destination.sin_addr), sizeof(destination));
}

ssize_t network::Socket::readData(void *buffer, size_t numBytes)
{
    // do nothing if buffer does not exist
    if (buffer == NULL)
    {
        return READ_WRITE_FAILURE;
    }

    // ensure socket is open and connected
    if ((!socketConnected) || (fileDescriptor == SOCKET_UNASSIGNED))
    {
        return READ_WRITE_FAILURE;
    }

#ifdef _WIN32
    int32_t destinationSize = sizeof(destination);
    return recvfrom(fileDescriptor, reinterpret_cast<char *>(buffer), numBytes, 0, reinterpret_cast<sockaddr *>(&destination), &destinationSize);
#else
    return read(fileDescriptor, buffer, numBytes);
#endif // _WIN32
}

int32_t network::Socket::getSocketOption(int32_t option, void *optionValue, socklen_t optionSize)
{
    if (fileDescriptor == SOCKET_UNASSIGNED)
    {
        return EBADF;
    }

#ifdef _WIN32
    if (getsockopt(fileDescriptor, SOL_SOCKET, option, reinterpret_cast<char *>(optionValue), &optionSize) != 0)
#else
    if (getsockopt(fileDescriptor, SOL_SOCKET, option, optionValue, &optionSize) != 0)
#endif // _WIN32
    {
        return EBADF;
    }

    // return error state in case an error occurred getting the option
    return getErrorState();
}

int32_t network::Socket::setSocketOption(int32_t option, void *optionValue, socklen_t optionSize)
{
    if (fileDescriptor == SOCKET_UNASSIGNED)
    {
        return EBADF;
    }

#ifdef _WIN32
    setsockopt(fileDescriptor, SOL_SOCKET, option, reinterpret_cast<char *>(optionValue), optionSize);
#else
    setsockopt(fileDescriptor, SOL_SOCKET, option, optionValue, optionSize);
#endif // _WIN32

    // return error state in case error occurred when setting option
    return getErrorState();
}

int32_t network::Socket::getErrorState()
{
    if (fileDescriptor == SOCKET_UNASSIGNED)
    {
        return EBADF;
    }

    int32_t error = 0;
    socklen_t size = sizeof(error);

#ifdef _WIN32
    if (getsockopt(fileDescriptor, SOL_SOCKET, SO_ERROR, reinterpret_cast<char *>(&error), &size) != 0)
#else
    if (getsockopt(fileDescriptor, SOL_SOCKET, SO_ERROR, &error, &size) != 0)
#endif // _WIN32
    {
        return EBADF;
    }

    return error;
}
