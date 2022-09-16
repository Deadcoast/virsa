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

// Boost includes
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/json/src.hpp>

// src includes
#include "VIRSA.h"

VIRSA::VIRSA(const char *configFile) :
    role(eNoRoleAssigned),
    port(0),
    videoOutput(eNoVideo),
    audioOutput(eNoAudio)
{
    // Set all characters of IP address to null terminator (makes it an empty string)
    memset(destinationAddress, '\0', sizeof(destinationAddress));

    parseConfigFile(configFile);
}

VIRSA::~VIRSA()
{
    
}

void VIRSA::parseConfigFile(const char *configFile)
{
    if (configFile == NULL)
    {
        fprintf(stderr, "Error: VIRSA config file is NULL\n");
        exit(EXIT_FAILURE);
    }

    try
    {
        boost::property_tree::ptree data;
        boost::property_tree::read_json(configFile, data);

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
            std::string raw = data.get<std::string>("address", "");

            if (raw.compare("") == 0)
            {
                fprintf(stderr, "Error: Failed to read VIRSA address from %s\n", configFile);
                exit(EXIT_FAILURE);
            }

            int32_t ipv4 = inet_addr(raw.c_str());

            // Ensure that IPv4 is valid
            if (ipv4 < 0)
            {
                fprintf(stderr, "Error: Invalid destination VIRSA address %s found in %s\n", raw.c_str(), configFile);
                exit(EXIT_FAILURE);
            }
        
            strcpy(destinationAddress, raw.c_str());
        }

        // Destination Port
        {
            int32_t raw = data.get<int32_t>("port", -1);

            if (raw == -1)
            {
                fprintf(stderr, "Error: Failed to find VIRSA port from %s\n", configFile);
                exit(EXIT_FAILURE);
            }

            port = static_cast<uint16_t>(raw);
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
        fprintf(stderr, "Error: Failed to parse file %s - %s\n", configFile, e.message().c_str());
        exit(EXIT_FAILURE);
    }
}
