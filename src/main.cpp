/**
 * Entry point for VIRSA.
 * 
 * @file main.cpp
 */

// System include
#include <cstdint>
#include <cstdio>

// Src includes
#include "buildConfig.h"
#include "VIRSA.h"

// Configuration includes
#include "configuration/ConfigurationManager.h"

int32_t main(int32_t argc, char **argv)
{
#ifdef BUILD_TYPE_DEBUG
    printf("Virtual Streaming Application (VIRSA): %llu.%llu.%llu-dirty\n", __VIRSA_VERSION_MAJOR__, __VIRSA_VERSION_MINOR__, __VIRSA_BUILD_NUMBER__);
#else
    printf("Virtual Streaming Application (VIRSA): %llu.%llu.%llu\n", __VIRSA_VERSION_MAJOR__, __VIRSA_VERSION_MINOR__, __VIRSA_BUILD_NUMBER__);
#endif

    VIRSA virsa("virsaConfig.json");

    return 0;
}
