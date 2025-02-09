set(MCU atmega328p)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(AVR_GCC_PATH "C:/Users/Legion/scoop/apps/avr-gcc/14.1.0")
set(CMAKE_C_COMPILER "${AVR_GCC_PATH}/bin/avr-gcc.exe")
set(CMAKE_CXX_COMPILER "${AVR_GCC_PATH}/bin/avr-g++.exe")


set(F_CPU 16000000UL)  # Adjust clock frequency as needed

set(CMAKE_C_FLAGS "-mmcu=${MCU} -Wall -Os -DF_CPU=${F_CPU}")

set(CMAKE_CXX_FLAGS "-mmcu=${MCU} -Wall -Os -DF_CPU=${F_CPU}")