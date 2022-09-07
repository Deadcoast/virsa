/**
 * Source code for VIRSA Configuration Manager.
 * 
 * @file ConfigurationManager.cpp
 */

// Configuration includes
#include "ConfigurationManager.h"

// src includes
#include "src/VIRSA.h"

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
    if (!parseVirsaConfig())
    {
        exit(EXIT_FAILURE);
    }
}

configuration::ConfigurationManager::~ConfigurationManager()
{

}

bool configuration::ConfigurationManager::parseVirsaConfig()
{
    boost::json::object data;

    return true;
}
