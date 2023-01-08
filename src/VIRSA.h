/**
 * Header file for VIRSA class.
 * 
 * @file VIRSA.h
 */

#ifndef VIRSA_H
#define VIRSA_H

// System includes
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>

// network includes
#include "network/sockets/ipv4/UDPSocket.h"

// Video includes
#include "video/VideoCapturer.h"

class VIRSA
{

public:

    enum Role
    {
        eNoRoleAssigned = 0,
        eStreamer = 1,
        eViewer = 2,
    };

    enum VideoInterface
    {
        eNoVideo = 0,
        eVideoHDMI = 1
    };

    enum AudioInterface
    {
        eNoAudio = 0,
        eAudioHDMI = 1
    };

    /**
     * Constructor for VIRSA.
     * 
     * @param configFile Path to VIRSA configuration file.
     */
    VIRSA(const char *configFile);

    /**
     * Destructor for VIRSA.
     */
    ~VIRSA();

    /**
     * Gets role of VIRSA application.
     * 
     * @return Configured role of VIRSA application.
     */
    Role getRole();

    /**
     * Gets IPv4 address of VISA peer.
     * 
     * @return Configured IPv4 address of streaming destination.
     */
    std::string getDestinationAddress();

    /**
     * Gets Streaming port of VISA peer.
     * 
     * @return Configured port to send streaming data to.
     */
    uint16_t getStreamingSendPort();

    /**
     * Gets streaming receive port.
     * 
     * @return Configured port to receive streaming data on.
     */
    uint16_t getStreamingReceivePort();

    /**
     * Gets Host Network interface.
     * 
     * @return Configured host network interface of VIRSA application.
     */
    std::string getHostNetworkInterface();

    /**
     * Get Video Output of VISA application.
     * 
     * @return Configured video output interface.
     */
    VideoInterface getVideoOutput();

    /**
     * Get audio output of VIRSA application.
     * 
     * @return Configured audio output interface.
     */
    AudioInterface getAudioOutput();

private:

    /**
     * Loads and parses config file data.
     */
    void parseConfigFile(const char *configFile);

    /**
     * Role of the VIRSA application.
     */
    Role role;

    /**
     * Address of VIRSA counterpart to send/receive data to/from.
     */
    std::string destinationAddress;

    /**
     * Port of VIRSA counterpart to send data to.
     */
    uint16_t streamingSendPort;

    /**
     * Port to receive streaming data.
     */
    uint16_t streamingReceivePort;

    /**
     * Name of host network interface to use for network traffic.
     */
    std::string hostNetworkInterface;

    /**
     * Video interface to capture/output.
     * 
     * Streamer => Video interface to capture (if one is to be captured).
     * 
     * Viewer => Video interface to send video data received from Streamer.
     */
    VideoInterface videoOutput;

    /**
     * Audio interface to capture/output.
     * 
     * Streamer => Audio interface to capture (if one is to be captured).
     * 
     * Viewer => Audio interface to send audio data received from Streamer.
     */
    AudioInterface audioOutput;

    /**
     * Instance for Video Capture (Streamer only).
     */
    Video::VideoCapturer *videoCapturer;

};

#endif // VIRSA_H
