/**
 * Source code for VIRSA Configuration Manager.
 * 
 * @file ConfigurationManager.cpp
 */

// Configuration includes
#include "ConfigurationManager.h"

// network includes
#include "network/ipv4/Socket.h"

configuration::ConfigurationManager *configuration::ConfigurationManager::getInstance()
{
    static ConfigurationManager configManager;
    return &configManager;
}

configuration::ConfigurationManager::ConfigurationManager() :
    role(VIRSA::eStreamer),
    destinationAddress(""),
    destinationPort(0)
{
    // If config can't be parsed, VIRSA cannot run
    if (!parseVirsaConfig(VIRSA_CONFIG_FILE))
    {
        exit(EXIT_FAILURE);
    }
}

configuration::ConfigurationManager::~ConfigurationManager()
{

}

bool configuration::ConfigurationManager::parseVirsaConfig(const char *filename)
{
    if (filename == NULL)
    {
        fprintf(stderr, "Error: Non-existant config file (NULL) detected.\n");
        return false;
    }

    boost::json::object data;

    try
    {
        // Role
        {
            const char *raw = data.at("role").as_string().c_str();
            
            if (strcmp(raw, "Streamer") == 0)
            {
                role = VIRSA::eStreamer;
            }
            else if (strcmp(raw, "Viewer") == 0)
            {
                role = VIRSA::eViewer;
            }
            else // Invalid role
            {
                fprintf(stderr, "Error: Invalid role specified in config.\n");
                return false;
            }
        }

        // Destination Address
        {
            const char *raw = data.at("address").as_string().c_str();

            // used to validate IPv4 address
            uint32_t destinationAddress = 0;

            // Validate IPv4 Address
            if (inet_pton(AF_INET, raw, &destinationAddress) < 0)
            {
                fprintf(stderr, "Error: Invalid IPv4 destination address.\n");
                return false;
            }

            this->destinationAddress = raw;
        }

        // Destination Port
        {
            destinationPort = static_cast<uint16_t>(data.at("port").as_uint64());
        }
    }
    catch (std::exception &e)
    {
        fprintf(stderr, "Error: failed to parse VIRSA config file: %s\n", filename);
        return false;
    }

    return true;
}
