/**
 * Source code for Video Capture library.
 * 
 * @file VideoCapturer.cpp
 */

// VIRSA includes
#include "src/VIRSA.h"

// Video includes
#include "video/VideoCapturer.h"

Video::VideoCapturer::VideoCapturer(VIRSA *virsa) :
    virsa(virsa),
    videoSocket(NULL)
{
    videoSocket = new network::ipv4::UDPSocket(virsa->getDestinationAddress().c_str(), virsa->getStreamingSendPort(), virsa->getHostNetworkInterface().c_str(), virsa->getStreamingReceivePort());
}

Video::VideoCapturer::~VideoCapturer()
{
    delete videoSocket;
}
