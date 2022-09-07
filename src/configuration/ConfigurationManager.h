/**
 * Header for VIRSA Configuration Manager.
 * 
 * @file ConfigurationManager.h
 */

#ifndef CONFIGURATION_MANAGER_H
#define CONFIGURATION_MANAGER_H

// System includes
#include <cstdint>
#include <cstdlib>

// Boost includes
#include <boost/json/src.hpp>

// src includes
#include "src/VIRSA.h"

namespace configuration
{

/**
 * Stores configuration values read from JSONs for the
 * current VIRSA instance.
 * 
 * NOTE: This is a singleton class.
 */
class ConfigurationManager
{

public:

    static constexpr const char *VIRSA_CONFIG_FILE = "./virsaConfig.json";

    /**
     * Gets instance of Configuration Manager.
     * 
     * @return Singleton instance of Configuration Manager.
     */
    static ConfigurationManager *getInstance();

private:

    /**
     * Constructor for Configuration Manager.
     * 
     * NOTE: Constructor is private to enforce singleton
     *       design pattern.
     */
    ConfigurationManager();

    /**
     * Destructor for Configuration Manager.
     * 
     * NOTE: Destructor is private to enforce singleton
     *       design pattern.
     */
    ~ConfigurationManager();

    /**
     * Parses VIRSA config file.
     * 
     * @bool True if file was parsed successfully; False otherwise.
     */
    static bool parseVirsaConfig();

    /**
     * Role of VIRSA instance.
     */
    VIRSA::Role role;

    /**
     * IP address that virsa will send/receive network traffic to/from.
     */
    const char *destinationAddress;

    /**
     * Port that virsa will send/receive network traffic to/from.
     */
    uint16_t destinationPort;

};

} // end namespace configuration

#endif // CONFIGURATION_MANAGER_H
