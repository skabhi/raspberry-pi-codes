#!/bin/bash

# Create build directory if it doesn't exist
mkdir -p build

# Navigate to the build directory
cd build

# Compile the code
g++ -o example_adxl345 ../examples/example_adxl345.cpp ../lib/adxl345.cpp -I../lib -lwiringPi

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Build successful!"
else
    echo "Build failed!"
fi

# Return to the root directory
cd ..