/**
 * Entry point for VIRSA.
 * 
 * @file main.cpp
 */

// System include
#include <cstdint>
#include <cstdio>

#include "configuration/ConfigurationManager.h"

// src includes
#include "buildConfig.h"
#include "VIRSA.h"

#include "network/UDPSocket.h"

int32_t main(int32_t argc, char **argv)
{
#ifdef BUILD_TYPE_DEBUG
    printf("Virtual Streaming Application (VIRSA): %lu.%lu.%lu-dirty\n", __VIRSA_VERSION_MAJOR__, __VIRSA_VERSION_MINOR__, __VIRSA_BUILD_NUMBER__);
#else
    printf("Virtual Streaming Application (VIRSA): %lu.%lu.%lu\n", __VIRSA_VERSION_MAJOR__, __VIRSA_VERSION_MINOR__, __VIRSA_BUILD_NUMBER__);
#endif

    configuration::ConfigurationManager *configManager = configuration::ConfigurationManager::getInstance();

    network::UDPSocket *test = new network::UDPSocket("10.0.0.115", 5050);

    char data[12];
    strcpy(data, "hello world");

    while (true)
    {
        test->sendData(data, sizeof(data));
    }

    delete test;

    return 0;
}
