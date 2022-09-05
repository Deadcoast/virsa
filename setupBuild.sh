#!/bin/bash
#
# Sets up cmake within the build directory on linux

# Configuration for build (debug, release, etc).
BUILD_TYPE=""
BUILD_PATH="./build"

echo "CWD: ${pwd}"

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -d|--debug)
            BUILD_TYPE="debug"
            shift # past argument
            ;;
        -r|--release)
            BUILD_TYPE="release"
            shift # past argument
            ;;
    esac
done

# Append the build type to the build directory path
BUILD_PATH+="/${BUILD_TYPE}"

# Ensure a valid build type was specified
if [ "${BUILD_TYPE}" = "" ]; then
    echo "Specify build type:"
    echo "-d | --debug"
    echo "-r | --release"
    exit 1
fi

# Delete the build directory (if one exists)
if [ -f ${BUILD_PATH} ]; then
    rm -rf ${BUILD_PATH}
fi

# Generate the build files
cmake -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" -B ${BUILD_PATH}

exit 0
