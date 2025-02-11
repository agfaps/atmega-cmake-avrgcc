set(MCU atmega328p)
set(DEFINE_MCU __AVR_ATmega328P__)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

# Assume avr-gcc (.exe) already in the PATH
if(WIN32)
    set(CMAKE_C_COMPILER "avr-gcc.exe")
    set(CMAKE_CXX_COMPILER "avr-g++.exe")
else()
    set(CMAKE_C_COMPILER "avr-gcc")
    set(CMAKE_CXX_COMPILER "avr-g++")
endif()

set(F_CPU 16000000UL)  # Adjust clock frequency as needed

set(CMAKE_C_FLAGS "-mmcu=${MCU} -Wall -Os -DF_CPU=${F_CPU} -D${DEFINE_MCU}")

set(CMAKE_CXX_FLAGS "-mmcu=${MCU} -Wall -Os -DF_CPU=${F_CPU} -D${DEFINE_MCU}")