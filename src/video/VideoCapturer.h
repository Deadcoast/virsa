/**
 * Header file for Video Capture library.
 * 
 * @file VideoCapturer.h
 */

#ifndef VIDEO_CAPTURER_H
#define VIDEO_CAPTURER_H

// System includes
#include <stdint.h>

// Network includes
#include "network/sockets/ipv4/UDPSocket.h"

class VIRSA;

namespace Video
{

/**
 * Captures video output and sends it to peer over network.
 */
class VideoCapturer
{

public:

    /**
     * Constructor for Video Capture.
     * 
     * @param virsa Instance of virsa application.
     */
    VideoCapturer(VIRSA *virsa);

    /**
     * Destructor for Video Capture.
     */
    ~VideoCapturer();

private:

    /**
     * Instance of virsa application.
     */
    VIRSA *virsa;

    /**
     * Network for sending UDP Socket.
     */
    network::ipv4::UDPSocket *videoSocket;

};

} // end namespace Video

#endif // VIDEO_CAPTURER_H
