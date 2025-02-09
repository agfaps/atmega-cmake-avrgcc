# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.13)

# Set the project name
project(atmega-gpio)

# Add your source files here
set(SOURCE_FILES src/main.c)
set(AVRDUDE_COM_PORT COM8)

# Add an executable target (This will create a .elf file)
add_executable(${PROJECT_NAME}.elf ${SOURCE_FILES})

# Set the name of the output hex file
set(HEX_OUTPUT ${PROJECT_NAME}.hex)

# Specify additional tools for converting .elf to .hex and getting sizes
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND avr-objcopy -O ihex -R .eeprom ${PROJECT_NAME}.elf ${HEX_OUTPUT}
    COMMAND avr-size ${PROJECT_NAME}.elf)
    # COMMAND ${AVR_GCC_PATH}/bin/avr-objcopy -O ihex -R .eeprom ${PROJECT_NAME}.elf ${HEX_OUTPUT}
    # COMMAND ${AVR_GCC_PATH}/bin/avr-size ${PROJECT_NAME}.elf)

# # Optionally, you can add a clean-up command to remove the .elf file after converting to .hex
# add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E remove ${PROJECT_NAME}.elf)

# Add a detect chip target using avrdude
add_custom_target(detect
    COMMAND avrdude -v -p m328p -carduino -P ${AVRDUDE_COM_PORT} -b115200
    COMMENT "Detecting the chip type via avrdude"
)

# Add a flash target using avrdude
add_custom_target(flash
    COMMAND avrdude -v -patmega328p -carduino -P ${AVRDUDE_COM_PORT} -b115200 -D -Uflash:w:${PROJECT_NAME}.hex:i
    DEPENDS ${PROJECT_NAME}.hex
    COMMENT "Flashing ${PROJECT_NAME}.hex to ATmega328P"
)


