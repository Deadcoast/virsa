/**
 * Source code for VIRSA Configuration Manager.
 * 
 * @file ConfigurationManager.cpp
 */

// Configuration includes
#include "ConfigurationManager.h"

// network includes
#include "network/Socket.h"

configuration::ConfigurationManager *configuration::ConfigurationManager::getInstance()
{
    static ConfigurationManager configManager;
    return &configManager;
}

configuration::ConfigurationManager::ConfigurationManager() :
    virsa(new VIRSA(VIRSA_CONFIG_FILE))
{

}

configuration::ConfigurationManager::~ConfigurationManager()
{
    delete virsa;
    virsa = NULL;
}
