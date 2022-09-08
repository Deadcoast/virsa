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

// network includes
#include "network/Socket.h"

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
    char destinationAddress[INET_ADDRSTRLEN];

    /**
     * Port of VIRSA counterpart to send/receive data to/from.
     */
    uint16_t port;

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

};

#endif // VIRSA_H
