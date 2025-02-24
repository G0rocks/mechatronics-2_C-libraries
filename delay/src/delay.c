/*
delay.c
Created by: Huldar
Date: 2025-02-24
For homework 4 in mechatronics 2 spring 2025
Description:
Program can delay operations with a given time interval (e.g. 100ms)
For use with the arduino MKR NB 1500 using the processor SAMD21G18A.
Datasheet: https://ww1.microchip.com/downloads/en/DeviceDoc/SAM_D21_DA1_Family_DataSheet_DS40001882F.pdf

Internal oscillators:
- OSC32K
- OSCULP32K
- OSC8M
- DFLL48M
- FDPLL96M

External oscillators:
- XOSC32K
- XOSC
*/

// INCLUDE
#include "delay.h"
#include "../../samd21g18a_pointers/samd21g18a_pointers.h" // SAMD21G18A pointers

enum time_unit {second, millisecond, microsecond};

// FUNCTION DECLARATIONS
// Get oscillator frequency
int _get_osc_freq(enum time_unit unit){
  // Read which clocks in use, return the highest frequency in use in Hz for seconds, kHz for ms and MHz for us
  // Note the waiting for loop takes 2 clock cycles per loop cycle so the returned frequency is half of the clock frequency
  // Check internal oscillators
  // Check OSC32K  

  // Check OSCULP32K enabled
  
  // Check OSC8M enabled
  if (*SYSCTRL_OSC8M_ptr & (1 << 1)) {
    switch (unit){
      case second:
        return 4000000; // [Hz]
        break;
      
      case millisecond:
        return 4000;  // [kHz]
        break;

      case microsecond:
        return 4;   // [MHz]
        break;
      
      default:
        break;
    }
  }

  // Check DFLL48M
  // SYSCTRL_DPLLSTATUS_ptr?
  
  // Check FDPLL96M

  // Check external oscillators
  // Check XOSC32K

  // Check XOSC

  return 0;
}

void wait_cycles(int iCycles){
  // Wait for iCycles, note each loop takes 2 clock cycles
  for (volatile int i = 0; i < iCycles; i++){}
}

// Delays for given number of seconds
void delay_s(int iSeconds){
  // Get highest frequency in use
  enum time_unit unit = second;
  int freq = _get_osc_freq(unit);

  // Find number of cycles needed to wait, and wait
  wait_cycles(freq * iSeconds);

  // Return
  return;
}

// Delays for given number of milliseconds
void delay_ms(int iMilliseconds){
    // Get highest frequency in use
    enum time_unit unit = millisecond;
    int freq = _get_osc_freq(unit);

    // Find number of cycles needed to wait, and wait
    wait_cycles((freq * iMilliseconds));
  
    // Return
    return;
}

// Delays for given number of microseconds
void delay_us(int iMicroseconds){
  // Get highest frequency in use
  enum time_unit unit = microsecond;
  int freq = _get_osc_freq(unit);

  // Find number of cycles needed to wait, and wait
  wait_cycles(freq * iMicroseconds);

  // Return
  return;
}


// MAIN FUNCTION
int main(void){
  *PORT_A_DIR_SET_ptr = *PORT_A_DIR_SET_ptr | 1 << 20;

  // Main loop
  while(1) {
    // Set PIN HIGH and test each delay
    *PORT_A_OUT_SET_ptr = *PORT_A_OUT_SET_ptr | 1 << 20;
    //delay_s(1);
    //delay_ms(1000);
    delay_us(1000000);

    // Set PIN LOW
    *PORT_A_OUT_CLR_ptr = *PORT_A_OUT_CLR_ptr | 1 << 20;
    //delay_s(1);
    //delay_ms(1000);
    delay_us(1000000);
  }
  return 0;
}