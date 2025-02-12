#!/bin/bash

# Exit immediately if a command fails
set -e

# Change to the correct working directory
cd /project

# Default behavior: Build firmware
if [ "$1" = "build" ]; then
    echo "Building AVR firmware..."
    sh setup_cmake.sh
    cd build
    make all

elif [ "$1" = "detect" ]; then
    echo "Detect microcontroller type..."
    avrdude -v -p m328p -c arduino -P /dev/ttyUSB0 -b115200

elif [ "$1" = "flash" ]; then
    echo "Flashing firmware to microcontroller..."
    avrdude -c arduino -p m328p -U flash:w:build/main.hex:i
    avrdude -v -p m328p -c arduino -P /dev/ttyUSB0 -b115200 -D -Uflash:w:atmega-gpio.hex:i

elif [ "$1" = "test" ]; then
    echo "Running GoogleTest unit tests..."
    cd test/googletest
    mkdir build
    cd build
    cmake -G "Unix Makefiles" ..
    make all
    ./run_tests

else
    echo "Command not recognized. Available options: build, detect, flash, test"
    exit 1
fi
