#!/bin/bash

echo ""
echo "Checking basic tools..."

# Function to check if a command exists
check_command() {
    if ! command -v "$1" &> /dev/null; then
        echo "❌ $1 is not installed."
        missing_tools=true
    else
        echo "✅ $1 is installed: $(command -v "$1")"
    fi
}

echo ""

# Initialize missing tools flag
missing_tools=false

# Check required tools
check_command avr-gcc
check_command cmake
check_command make
check_command avrdude

# Exit with error if any tool is missing
if [ "$missing_tools" = true ]; then
    echo "Some required tools are missing. Please install them before proceeding."
    exit 1
else
    echo ""
    echo "All required tools are installed. ✅"
    echo ""
fi

BUILD_DIR="build"

if [ -d "$BUILD_DIR" ]; then
    echo "Removing existing $BUILD_DIR directory.."
    echo ""
    rm -rf "$BUILD_DIR"
else
    echo "$BUILD_DIR directory not found, skipping removal."
    echo ""
fi

echo "Generating Makefile from CMakeLists.txt.."
echo ""

mkdir -p build
cd build
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE="cmake/avr-gcc-toolchain.cmake" ..

exit 0
