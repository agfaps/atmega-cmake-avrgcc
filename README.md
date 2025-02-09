# ATmega Project

This project demonstrates simple project configuration for ATmega328P in an arduino board.
It include simple built-in LED blinking example using VSCode, avr-gcc, avrdude, and built-in arduino bootloader.

## Generate .vscode setting file

To enable proper intellisense in VSCode, we need to setup .vscode settings (currently for windows, you can modify it for Linux/MacOS):

generate .vscode setting
C/C++: Edit Configurations (UI)/(JSON)

make c_cpp_properties.json file look like this for windows environment:

```json
{
    "configurations": [
        {
            "name": "AVR",
            "includePath": [
                "C:/Users/${USER}/scoop/apps/avr-gcc/14.1.0/avr/include",
                "C:/Users/${USER}/scoop/apps/avr-gcc/14.1.0/bin/../lib/gcc/avr/14.1.0/include"
            ],
            "defines": ["__AVR_ATmega328P__"],
            "windowsSdkVersion": "10.0.22621.0",
            "compilerPath": "C:/Users/${USER}/scoop/apps/avr-gcc/14.1.0/bin/avr-gcc.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```

## CMake Setup

```sh
sh setup_cmake.sh
```

## Build and flash

```sh
make all
make detect
make flash
```

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENCE) file for details.
