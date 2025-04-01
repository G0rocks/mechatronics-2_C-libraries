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
void blink_success() ;

/// @brief Blinks the inverse of the success signal (half the blink_heartbeat function)
void blink_success_inverse();

/// @brief  Blinks to signal failure
void blink_fail();

/// @brief  Blinks the inverse of the fail signal
void blink_fail_inverse();

/// @brief  Blinks n times
/// @param  n   Number of blinks
void blink_n_times(unsigned char n);

/// @brief Blink strobe short
void blink_strobe_short();

/// @brief  Blinks two heartbeats
void blink_heartbeat();

/// @brief  Blinks 2 heartbeats with the OFF period
void blink_heartbeat_inverse();

/// @brief  Blinks a 3 digit number. First blinks success, then the first digit, success, second digit, success, third digit, success.
/// @param
void blink_3_digit_number(unsigned int num);

#endif