/*
samd21g18a_registers.h
Created by: Huldar
Date: 2025-03-03

Description:
Definitions and functions for register manipulation.
For use with the arduino MKR NB 1500 using the processor SAMD21G18A.
Datasheet: https://ww1.microchip.com/downloads/en/DeviceDoc/SAM_D21_DA1_Family_DataSheet_DS40001882F.pdf
*/

#include "samd21g18a_pointers.h"

// Define register type with pointer to register address. Note "register" is a reserved keyword in C, so we use "register_type" instead.
typedef struct {
    unsigned char num_bytes;
    unsigned int address;
} register_type;


// REGISTER FUNCTIONS

// register bit read
char register_bit_read(register_type reg, char bit_num) {
    // Reads the value of the given register
    // reg: register struct
    // bit_num: bit number to read
    // Switch depending on the number of bytes in the register
    switch (reg.num_bytes) {
        case 1:
            return (*(unsigned char*)reg.address >> bit_num) & 1;   // Returns for char register
        case 2:
            return (*(unsigned short*)reg.address >> bit_num) & 1;  // Returns for short register
        case 4:
            return (*(unsigned int*)reg.address >> bit_num) & 1;    // Returns for int register
        default:
            return -1;  // An error occured, number of bytes not supported, returning -1
    }
}

// register bit write LOW
char register_bit_write_LOW(register_type reg, char bit_num) {
    // Writes 0 to the given register
    // reg: register struct
    // bit_num: bit number to write
    // Switch depending on the number of bytes in the register
    switch (reg.num_bytes) {
        case 1:
            *(unsigned char*)reg.address = *(unsigned char*)reg.address & ~(1 << bit_num);   // Writes for char register
            break;
        case 2:
            *(unsigned short*)reg.address = *(unsigned short*)reg.address & ~(1 << bit_num);  // Writes for short register
            break;
        case 4:
            *(unsigned int*)reg.address = *(unsigned int*)reg.address & ~(1 << bit_num);    // Writes for int register
            break;
        default:
            return -1;  // An error occured, number of bytes not supported, returning -1
    }
    return 0;
}

// register bit write HIGH
char register_bit_write_HIGH(register_type reg, char bit_num) {
    // Writes 1 to the given register
    // reg: register struct
    // bit_num: bit number to write
    // Switch depending on the number of bytes in the register
    switch (reg.num_bytes) {
        case 1:
            *(unsigned char*)reg.address = *(unsigned char*)reg.address | 1 << bit_num;   // Writes for char register
            break;
        case 2:
            *(unsigned short*)reg.address = *(unsigned short*)reg.address | 1 << bit_num;  // Writes for short register
            break;
        case 4:
            *(unsigned int*)reg.address = *(unsigned int*)reg.address | 1 << bit_num;    // Writes for int register
            break;
        default:
            return -1;  // An error occured, number of bytes not supported, returning -1
    }
    return 0;
}

// register bits write. Writes the given value to multiple bits simultaneously
char register_bits_write(register_type reg, char bit_num, char num_bits, int value) {
    // Writes the given value to the given bits
    // reg: register struct
    // bit_num: lowest bit number to write. The value will be written to the bits from bit_num to bit_num + num_bits
    // num_bits: number of bits to write, must be between 1 and 32, both included
    // value: value to write
    // Switch depending on the number of bytes in the register, set the bits to the given value by first making a bitmask with all bits as 1 and 0 at the bits to write, then AND that to the register (this way we don't mess with the previous values) then OR the value shifted to the correct position to update the bits we want to modify
    switch (reg.num_bytes) {
        case 1:
            *(unsigned char*)reg.address = (*(unsigned char*)reg.address & ~(((1 << num_bits) - 1) << bit_num)) | ((unsigned char)value << bit_num);   // Writes for char register
            break;
        case 2:
            *(unsigned short*)reg.address = (*(unsigned short*)reg.address & ~(((1 << num_bits) - 1) << bit_num)) | ((unsigned short)value << bit_num);  // Writes for short register
            break;
        case 4:
            *(unsigned int*)reg.address = (*(unsigned int*)reg.address & ~(((1 << num_bits) - 1) << bit_num)) | ((unsigned int)value << bit_num);    // Writes for int register
            break;
        default:
            return -1;  // An error occured, number of bytes not supported, returning -1
    }
    return 0;
}

// register bit write. Writes custom value to the given register, the value is cast to the register size
// WARNING: This function overwrites the entire register, regardless of the previous values. USE WITH CAUTION!
// CURRENTLY NOT WORKING!
char register_write_whole(register_type reg, int value) {
    // Writes the given value to the given register
    // reg: register struct
    // value: value to write
    // Switch depending on the number of bytes in the register
    switch (reg.num_bytes) {
        case 1:
            *(unsigned char*)reg.address = (unsigned char)value;   // Writes for char register
            break;
        case 2:
            *(unsigned short*)reg.address = (unsigned short)value;  // Writes for short register
            break;
        case 4:
            *(unsigned int*)reg.address = (unsigned int)value;    // Writes for int register
            break;
        default:
            return -1;  // An error occured, number of bytes not supported, returning -1
    }
    return 0;   
}