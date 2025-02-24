/*
* delay.h
* Created by: Huldar
* Date: 2025-02-24
* For homework 4 in mechatronics 2 spring 2025
* Description:
* For use with the arduino MKR NB 1500 using the processor SAMD21G18A
* Program can delay operations with a given time interval (e.g. 100ms)
*/

// Wait num_cycles number of clock cycles
void wait_cycles(int num_cycles);

// Delay for iSeconds many seconds
void delay_s(int iSeconds);

// Delay for iMilliseconds many milliseconds
void delay_ms(int iMilliseconds);

// Delay for iMicroseconds many microseconds
void delay_us(int iMicroseconds);