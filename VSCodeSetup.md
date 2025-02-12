# Visual Studio Code

## Generate .vscode setting file

To enable proper IntelliSense in VSCode, we need to setup C/C++ Configuration settings (C/C++ Extension Pack).  
Since we have avr-gcc for AVR project and gcc for CppUTest-Unity-GoogleTest, we need to create two C/C++ Configuration settings.  
We can switch between settings by clicking in bottom right corner (Switching between AVR-Atmega and Host-Unit-Test) so IntelliSense do not report error information.

1. Hold `Ctrl+Shift+P`
2. Choose C/C++: Edit Configurations (UI)
3. Give Configuration name: AVR-ATmega
4. Specify Compiler path: `C:/Users/${USER}/scoop/shims/avr-gcc.exe (or /usr/bin/gcc)`
5. Compiler arguments: (no need to fill, we just specify it in CMakeLists.txt)
6. IntelliSense mode: `linux-gcc-x64`
7. Include path: populate with include folder per line in your system.  
    Example:
    ```sh
    ${workspaceFolder}/include
    C:/Users/${USER}/scoop/apps/avr-gcc/14.1.0/avr/include
    C:/Users/${USER}/scoop/apps/avr-gcc/14.1.0/bin/../lib/gcc/avr/14.1.0/include
    ```
8. Defines: at least add `__AVR_ATmega328P__` so IntelliSense can show the right section/files
9. C standard: c17
10. C++ standard: c++17

Profile for CppUTest:

1. Hold `Ctrl+Shift+P`
2. Choose C/C++: Edit Configurations (UI)
3. Give Configuration name: Host-Unit-Test
4. Specify Compiler path: `C:/Users/${USER}/scoop/apps/gcc/current/bin/gcc.exe (or /usr/bin/g++)`
5. Compiler arguments: (no need to fill, we just specify it in CMakeLists.txt)
6. IntelliSense mode: `linux-gcc-x64`
7. Include path: populate with include folder per line in your system.  
    Example:
    ```sh
    ${workspaceFolder}/include
    ${workspaceFolder}/test/cpputest/include/CppUTest
    ${workspaceFolder}/test/cpputest/include/CppUTestExt
    ${workspaceFolder}/test/googletest/include
    ${workspaceFolder}/test/unity/unity
    ```
8. Defines: `CPPUTEST_USE_OWN_CONFIGURATION`
9. C standard: c17
10. C++ standard: c++17


Now `.vscode/c_cpp_properties.json` file will look like this(Windows):
```json
{
    "configurations": [
        {
            "name": "AVR-ATmega",
            "includePath": [
                "${workspaceFolder}/include",
                "C:/Users/${USER}/scoop/apps/avr-gcc/14.1.0/avr/include",
                "C:/Users/${USER}/scoop/apps/avr-gcc/14.1.0/bin/../lib/gcc/avr/14.1.0/include"
            ],
            "defines": [
                "__AVR_ATmega328P__"
            ],
            "windowsSdkVersion": "10.0.22621.0",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64",
            "configurationProvider": "ms-vscode.cmake-tools",
            "compilerPath": "C:/Users/${USER}/scoop/shims/avr-gcc.exe"
        },
        {
            "name": "Host-Unit-Test",
            "includePath": [
                "${workspaceFolder}/include",
                "${workspaceFolder}/test/cpputest/include/CppUTest",
                "${workspaceFolder}/test/cpputest/include/CppUTestExt",
                "${workspaceFolder}/test/googletest/include",
                "${workspaceFolder}/test/unity/unity"
            ],
            "defines": [
                "CPPUTEST_USE_OWN_CONFIGURATION"
            ],
            "windowsSdkVersion": "10.0.22621.0",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64",
            "compilerPath": "C:/Users/${USER}/scoop/apps/gcc/current/bin/g++.exe"
        }
    ],
    "version": 4
}
```

NOTE: `avr-gcc` version used at the time is `14.1.0`, yours can vary.