/*
samd21g18a_registers.h
Created by: Huldar
Date: 2025-03-03

Description:
Definitions and functions for register manipulation.
For use with the arduino MKR NB 1500 using the processor SAMD21G18A.
Datasheet: https://ww1.microchip.com/downloads/en/DeviceDoc/SAM_D21_DA1_Family_DataSheet_DS40001882F.pdf
*/

// Include guard
#ifndef _samd21g18a_registers_
#define _samd21g18a_registers_

#include "samd21g18a_pointers.h"



// Define register type with pointer to register address. Note "register" is a reserved keyword in C, so we use "register_type" instead.
typedef struct {
    unsigned char num_bytes;
    unsigned int address;
} register_type;


// REGISTER FUNCTIONS

// register bit read
char register_bit_read(register_type reg, char bit_num);

// register bit write LOW
char register_bit_write_LOW(register_type reg, char bit_num);

// register bit write HIGH
char register_bit_write_HIGH(register_type reg, char bit_num);

// register bits write. Writes the given value to multiple bits simultaneously
char register_bits_write(register_type reg, char bit_num, char num_bits, int value);

// register bit write. Writes custom value to the given register, the value is cast to the register size
// WARNING: This function overwrites the entire register, regardless of the previous values. USE WITH CAUTION!
// CURRENTLY NOT WORKING!
char register_write_whole(register_type reg, int value);

/// @brief Reads the given bit from the given register until it is HIGH. Tries a given number of attempts
/// @param reg register struct
/// @param bit_num bit number to wait for
/// @param attempts number of attempts to wait for synchronization
/// @return 0 if success, -1 if failed
char register_wait_for_sync_HIGH(register_type reg, char bit_num, unsigned int attempts);

/// @brief Reads the given bit from the given register until it is LOW. Tries a given number of attempts
/// @param reg register struct
/// @param bit_num bit number to wait for
/// @param attempts number of attempts to wait for synchronization
/// @return 0 if success, 4 if failed
char register_wait_for_sync_LOW(register_type reg, char bit_num, unsigned int attempts) {

#endif