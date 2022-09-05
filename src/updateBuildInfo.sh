#!/bin/bash
#
# Updates build configuration for given executable.
#
# NOTE: This script should only be called by an automated
#       process such as CMake during a build event.

EXECUTABLE_NAME=""
CONFIG_FILE="buildConfig.h"

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        virsa)
            EXECUTABLE_NAME="VIRSA"
            shift # past argument
            ;;
        -d|--directory-to-config-file)
            CONFIG_FILE="${2%/}/${CONFIG_FILE}"
            shift # past argument
            shift #past value
            ;;
    esac
done

# Ensure necessary information was supplied and correct
if [ "${EXECUTABLE_NAME}" = "" ]; then
    echo "Error: Invalid executable specified."
    exit 1
elif [ ! -f "${CONFIG_FILE}" ]; then
    echo "Error: config file not found at: ${CONFIG_FILE}"
    exit 1
fi

# Extract build number for executable
BUILD_NUMBER=$(grep "__${EXECUTABLE_NAME}_BUILD_NUMBER__" ${CONFIG_FILE} | sed "s/constexpr uint64_t __${EXECUTABLE_NAME}_BUILD_NUMBER__ = //g" | sed "s/[^0-9]*//g")

# Increment build number and replace it back in config file
BUILD_NUMBER=$((${BUILD_NUMBER} + 1))

sed -i "s/__${EXECUTABLE_NAME}_BUILD_NUMBER__ = [0-9]*llu/__${EXECUTABLE_NAME}_BUILD_NUMBER__ = ${BUILD_NUMBER}llu/g" ${CONFIG_FILE}

exit 0
