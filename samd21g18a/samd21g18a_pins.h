/*
samd21g18a_pins.h
Created by: Huldar
Date: 2025-02-24

Description:
Structs, enums etc. and functions for pin manipulation.
For use with the arduino MKR NB 1500 using the processor SAMD21G18A.
Datasheet: https://ww1.microchip.com/downloads/en/DeviceDoc/SAM_D21_DA1_Family_DataSheet_DS40001882F.pdf
*/

// Include guard
#ifndef _samd21g18a_pins_
#define _samd21g18a_pins_

#include "samd21g18a_pointers.h"


// Define pin type with port and pin number
typedef struct {
    unsigned int port_offset;
    unsigned char pin_number;
} pin;

// Define pins
#define PA20 ((pin) {PORT_A_OFFSET, 20})


// PIN FUNCTIONS
// Set pin as output
void set_pin_as_output(pin p) {
    // Set pin as output
    *(PORT_A_DIR_SET_ptr + p.port_offset) = (*PORT_A_DIR_SET_ptr + p.port_offset) | 1 << p.pin_number;
}

// Set pin output HIGH, note pin must be set as output before calling this function
void set_pin_HIGH(pin p) {
    // Set pin HIGH
    *(PORT_A_OUT_SET_ptr + p.port_offset) = (*PORT_A_OUT_SET_ptr + p.port_offset) | 1 << p.pin_number;
}

// Set pin output LOW, note pin must be set as output before calling this function
void set_pin_LOW(pin p) {
    // Set pin HIGH
    *(PORT_A_OUT_CLR_ptr + p.port_offset) = (*PORT_A_OUT_CLR_ptr + p.port_offset) | 1 << p.pin_number;
}

#endif