/**
 * Source code for IPv4 Socket.
 * 
 * @file Socket.cpp
 */

// Network includes
#include "network/ipv4/Socket.h"

network::IPv4::Socket::Socket(const char *address, uint16_t port, int32_t protocol) :
    fileDescriptor(SOCKET_UNASSIGNED),
    address(address),
    port(port),
    socketConnected(false)
{
    fileDescriptor = socket(AF_INET, SOL_SOCKET, protocol);
}

network::IPv4::Socket::~Socket()
{
    disconnect();
}

void network::IPv4::Socket::disconnect()
{
    if (fileDescriptor != SOCKET_UNASSIGNED)
    {
        close(fileDescriptor);
    }

    return;
}

bool network::IPv4::Socket::isConnected()
{
    return socketConnected;
}

ssize_t network::IPv4::Socket::sendData(void *data, size_t numBytes)
{
    // do nothing if data does not exist
    if (data == NULL)
    {
        return 0;
    }

    // ensure socket is open and connected
    if ((!socketConnected) || (fileDescriptor == SOCKET_UNASSIGNED))
    {
        return 0;
    }

    return send(fileDescriptor, data, numBytes, 0);
}

ssize_t network::IPv4::Socket::readData(void *buffer, size_t numBytes)
{
    // do nothing if buffer does not exist
    if (buffer == NULL)
    {
        return 0;
    }

    // ensure socket is open and connected
    if ((!socketConnected) || (fileDescriptor == SOCKET_UNASSIGNED))
    {
        return 0;
    }

    return read(fileDescriptor, buffer, numBytes);
}

int32_t network::IPv4::Socket::getSocketOption(int32_t option, void *optionValue, socklen_t optionSize)
{
    if (fileDescriptor == SOCKET_UNASSIGNED)
    {
        return EBADF;
    }

    if (getsockopt(fileDescriptor, SOL_SOCKET, option, optionValue, &optionSize) != 0)
    {
        return EBADF;
    }

    // return error state in case an error occurred getting the option
    return getErrorState();
}

int32_t network::IPv4::Socket::setSocketOption(int32_t option, void *optionValue, socklen_t optionSize)
{
    if (fileDescriptor == SOCKET_UNASSIGNED)
    {
        return EBADF;
    }

    setsockopt(fileDescriptor, SOL_SOCKET, option, optionValue, optionSize);

    // return error state in case error occurred when setting option
    return getErrorState();
}

int32_t network::IPv4::Socket::getErrorState()
{
    if (fileDescriptor == SOCKET_UNASSIGNED)
    {
        return EBADF;
    }

    int32_t error = 0;
    socklen_t size = sizeof(error);

    if (getsockopt(fileDescriptor, SOL_SOCKET, SO_ERROR, &error, &size) != 0)
    {
        return EBADF;
    }

    return error;
}
