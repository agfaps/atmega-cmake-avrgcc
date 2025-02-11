# ATmega VSCode Project Template

This project demonstrates simple project configuration for ATmega328P in an arduino board.
It include simple built-in LED blinking example using VSCode, avr-gcc, avrdude, and built-in arduino bootloader.

## Generate .vscode setting file

To enable proper intellisense in VSCode, we need to setup .vscode settings.
Since we have avr-gcc for AVR project and GCC for CppUTest, we need to create two
profiles. We can switch between profiles so IntelliSense do not report error information.
For Unity, we can use AVR profiles/configuration.


1. Hold `Ctrl+Shift+P`
2. Choose C/C++: Edit Configurations (UI)
3. Give Configuration name: AVR
4. Specify Compiler path: `${PATH_TO}/avr-gcc (or avr-gcc.exe)`
5. Compiler arguments: (no need to fill, we just specify it in CMakeLists.txt)
6. IntelliSense mode: `linux-gcc-x64`
7. Include path: populate with include folder per line in your system.
   Example:
   ```sh
   ${workspaceFolder}/include
   ${workspaceFolder}/test/unity/unity
   PATH_TO/avr-gcc/14.1.0/avr/include
   PATH_TO/avr-gcc/14.1.0/bin/../lib/gcc/avr/14.1.0/include
   ```
8. Defines: at least add `__AVR_ATmega328P__` so IntelliSense can show the right section/files
9. C standard: c17
10. C++ standard: c++17

Profile for CppUTest:

1. Hold `Ctrl+Shift+P`
2. Choose C/C++: Edit Configurations (UI)
3. Give Configuration name: Host-GCC
4. Specify Compiler path: `${PATH_TO}/g++ (or g++.exe)`
5. Compiler arguments: (no need to fill, we just specify it in CMakeLists.txt)
6. IntelliSense mode: `linux-gcc-x64`
7. Include path: populate with include folder per line in your system.
   Example:
   ```sh
    ${workspaceFolder}/include
    ${workspaceFolder}/test/cpputest/include/CppUTest
    ${workspaceFolder}/test/cpputest/include/CppUTestExt
   ```
8. Defines: `CPPUTEST_USE_OWN_CONFIGURATION`
9. C standard: c17
10. C++ standard: c++17


Now `.vscode/c_cpp_properties.json` file will look like this(Windows):
```json
{
    "configurations": [
        {
            "name": "AVR",
            "includePath": [
                "${workspaceFolder}/include",
                "${workspaceFolder}/test/unity/unity",
                "C:/Users/${USER}/scoop/apps/avr-gcc/14.1.0/avr/include",
                "C:/Users/${USER}/scoop/apps/avr-gcc/14.1.0/bin/../lib/gcc/avr/14.1.0/include"
            ],
            "windowsSdkVersion": "10.0.22621.0",
            "compilerPath": "C:/Users/${USER}/scoop/apps/avr-gcc/14.1.0/bin/avr-gcc.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64",
            "defines": [
                "__AVR_ATmega328P__"
            ]
        },
        {
            "name": "Host-GCC",
            "includePath": [
                "${workspaceFolder}/include",
                "${workspaceFolder}/test/cpputest/include/CppUTest",
                "${workspaceFolder}/test/cpputest/include/CppUTestExt"
            ],
            "windowsSdkVersion": "10.0.22621.0",
            "compilerPath": "C:/ProgramData/mingw64/mingw64/bin/g++.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64",
            "defines": [
                "CPPUTEST_USE_OWN_CONFIGURATION"
            ],
            "mergeConfigurations": false,
            "browse": {
                "path": [
                    "${workspaceFolder}/include",
                    "${workspaceFolder}/test/cpputest/include",
                    "${workspaceFolder}/src/atmega-cmake-avrgcc"
                ],
                "limitSymbolsToIncludedHeaders": true
            }
        }
    ],
    "version": 4
}
```

NOTE: `avr-gcc` version used at the time is `14.1.0`, yours can vary.

## AVR CMake Setup

Change COM port name in CMakeLists.txt in your OS.

```sh
set(AVRDUDE_COM_PORT COM8)
set(AVRDUDE_COM_PORT /dev/ttyUSB0)
```

Run setup script.

```sh
sh setup_cmake.sh
```

## Build and flash

Compile, detect chip type, and flash.

```sh
make all
make detect
make flash
```

## Building Unit Tests

### Unity

Steps to build Unity test (from `${workspaceFolder}`):
```sh
cd test/unity
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make all
./run_tests(.exe)
```

### CppUTest

Steps to build CppUTest test (from `${workspaceFolder}`):
```sh
cd test/cpputest
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make all
./run_tests(.exe)
```

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENCE) file for details.
