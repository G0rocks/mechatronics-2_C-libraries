/*
samd21g18a_blinker.h
Created by: Huldar
Date: 2025-03-10

Description:
This library contains functions for blinking the onboard LED to signal whatever the programmer wants to tsignal
NOTE: THIS LIBRARY ASSUMES THAT THE LED IS CONNECTED TO PIN PA20 AND THE PIN IS CONFIGURED AS OUTPUT!!!
All functions start with a short delay.
All inverse functions start by turning the LED on before waiting the start delay and add a short delay at the end before turning the LED back off.
For use with the arduino MKR NB 1500 using the processor SAMD21G18A.
Datasheet: https://ww1.microchip.com/downloads/en/DeviceDoc/SAM_D21_DA1_Family_DataSheet_DS40001882F.pdf
*/

// Include guard
#ifndef _samd21g18a_blinker_
#define _samd21g18a_blinker_

#include "samd21g18a_pointers.h"
#include "samd21g18a_registers.h"
#include "delay.h"

// FUNCTIONS
//##############################################################

/// @brief  Success signal (half the blink_heartbeat function)
void blink_success() {
    delay_ms(500);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
}

/// @brief Blinks the inverse of the success signal (half the blink_heartbeat function)
void blink_success_inverse() {
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(500);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(500);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);

}

/// @brief  Blinks to signal failure
void blink_fail() {
    delay_ms(500);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_s(1);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_s(1);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_s(1);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
}

/// @brief  Blinks the inverse of the fail signal
void blink_fail_inverse() {
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(500);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_s(1);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_s(1);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_s(1);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(500);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
}

/// @brief  Blinks n times
/// @param  n   Number of blinks
void blink_n_times(unsigned char n) {
    delay_ms(500);
    for (unsigned char i = 0; i <= n; i++) {
        register_bit_write_HIGH(PORT_A_OUT_SET, 20);
        delay_ms(250);
        register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
        delay_ms(250);
    }
}

/// @brief  Blinks two heartbeats
void blink_heartbeat() {
    // Sign of life
    delay_ms(500);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_ms(500);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
}

/// @brief  Blinks 2 heartbeats with the OFF period
void blink_heartbeat_inverse() {
    // Sign of life
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(500);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(500);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    delay_ms(100);
    register_bit_write_HIGH(PORT_A_OUT_SET, 20);
    delay_ms(500);
    register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
}

#endif