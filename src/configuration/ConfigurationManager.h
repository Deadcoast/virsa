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
#include <string>

// src includes
#include "VIRSA.h"

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
     * Instance of VIRSA application.
     */
    VIRSA *virsa;

};

} // end namespace configuration

#endif // CONFIGURATION_MANAGER_H
