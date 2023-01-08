/**
 * Source code for VIRSA class.
 * 
 * @file VIRSA.cpp
 */

/**
 * Define to help boost JSON run on embedded systems
 * (according to documentation).
 */
#define BOOST_JSON_STACK_BUFFER_SIZE 1024

// System includes
#ifdef _WIN32
#include <direct.h>
#define getCurrentDirectory _getcwd
#else
#include <unistd.h>
#define getCurrentDirectory getcwd
#endif

// Boost includes
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/json/src.hpp>

// src includes
#include "VIRSA.h"

VIRSA::VIRSA(const char *configFile) :
    role(eNoRoleAssigned),
    streamingSendPort(0),
    streamingReceivePort(0),
    videoOutput(eNoVideo),
    audioOutput(eNoAudio),
    streamingSocket(NULL)
{
    parseConfigFile(configFile);

    // Open socket(s)
    streamingSocket = new network::ipv4::UDPSocket(destinationAddress.c_str(), streamingSendPort, hostNetworkInterface.c_str(), streamingReceivePort);
}

VIRSA::~VIRSA()
{
    // Close socket(s)
    delete streamingSocket;
}

void VIRSA::parseConfigFile(const char *configFile)
{
    if (configFile == NULL)
    {
        fprintf(stderr, "Error: VIRSA config file is NULL\n");
        exit(EXIT_FAILURE);
    }

    // Get absolute path to config file
    const uint32_t MAX_FILEPATH_STRLEN = 500;
    char buffer[MAX_FILEPATH_STRLEN];
    getCurrentDirectory(buffer, MAX_FILEPATH_STRLEN);
    std::string filepath(buffer);
#ifdef _WIN32
    filepath.append("\\");
#else
    filepath.append("/");
#endif
    filepath.append(configFile);

    try
    {
        boost::property_tree::ptree data;

        boost::property_tree::read_json(filepath, data);

        // VIRSA Role
        {
            std::string raw = data.get<std::string>("role", "");

            if (raw.compare("") == 0)
            {
                fprintf(stderr, "Error: Failed to read VIRSA role from %s\n", configFile);
                exit(EXIT_FAILURE);
            }

            if (raw.compare("Streamer") == 0)
            {
                role = eStreamer;
            }
            else if (raw.compare("Viewer") == 0)
            {
                role = eStreamer;
            }
            else
            {
                fprintf(stderr, "Error: Invalid VIRSA role specified in %s\n", configFile);
                exit(EXIT_FAILURE);
            }
        }

        // Destination IPv4
        {
            destinationAddress = data.get<std::string>("streamingIPv4", "");

            if (destinationAddress.empty())
            {
                fprintf(stderr, "Error: Failed to read VIRSA address from %s\n", configFile);
                exit(EXIT_FAILURE);
            }
        }

        // streaming destination port
        {
            streamingSendPort = data.get<uint16_t>("streamingSendPort", 0);
        }

        // Streaming receive port
        {
            streamingReceivePort = data.get<uint16_t>("streamingReceivePort", 0);
        }

        // Host Network Interface Name
        {
            hostNetworkInterface = data.get<std::string>("networkInterface", "");

            if (hostNetworkInterface.empty())
            {
                fprintf(stderr, "Error: Failed to read VIRSA host network interface from %s\n", configFile);
                exit(EXIT_FAILURE);
            }
        }

        // Video Output
        {
            std::string raw = data.get<std::string>("videoOutput", "");

            if (raw.compare("") == 0)
            {
                fprintf(stderr, "Error: Failed to read video output from %s\n", configFile);
                exit(EXIT_FAILURE);
            }

            if (raw.compare("HDMI") == 0)
            {
                videoOutput = eVideoHDMI;
            }
            else
            {
                fprintf(stderr, "Error: Invalid video output from %s\n", configFile);
                exit(EXIT_FAILURE);
            }
        }

        // Audio Output
        {
            std::string raw = data.get<std::string>("audioOutput", "");

            if (raw.compare("") == 0)
            {
                fprintf(stderr, "Error: Failed to read audio output from %s\n", configFile);
                exit(EXIT_FAILURE);
            }

            if (raw.compare("HDMI") == 0)
            {
                audioOutput = eAudioHDMI;
            }
            else
            {
                fprintf(stderr, "Error: Invalid audio output from %s\n", configFile);
                exit(EXIT_FAILURE);
            }
        }
    }
    catch (boost::property_tree::json_parser_error &e)
    {
        fprintf(stderr, "Error: Failed to parse file %s - %s\n", filepath.c_str(), e.message().c_str());
        exit(EXIT_FAILURE);
    }
}
