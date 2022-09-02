#! /bin/bash
#
# Sets up cmake within the build directory on linux

# Remove the existing build directory
rm -rf build/

# Re-create the build directory from scratch
mkdir build/

cd build/
cmake ..
cd ..
