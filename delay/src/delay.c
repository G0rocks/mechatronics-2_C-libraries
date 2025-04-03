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
#include <delay.h>
#include <samd21g18a_pins.h>
#include <samd21g18a_pointers.h>

enum time_unit {second, millisecond, microsecond};

// FUNCTION DECLARATIONS
int _get_osc_freq(enum time_unit unit){
  // Read which clocks in use, return half of the highest frequency in use in Hz for seconds, kHz for ms and MHz for us
  // Note the waiting for loop takes 2 clock cycles per loop cycle so the returned frequency is half of the clock frequency
  // Check internal oscillators
  // Check OSC32K

  // Check OSCULP32K enabled
  
  // Check OSC8M enabled
  if (*SYSCTRL_OSC8M_ptr & (1 << 1)) {
    switch (unit){
      case second:
        return 8000000; // [Hz]
        break;
      
      case millisecond:
        return 8000;  // [kHz]
        break;

      case microsecond:
        return 8;   // [MHz]
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

// Get oscillator frequency
// CURRENTLY ONLY VALID FOR 8MHz OSCILLATOR
int _get_osc_freq_halved(enum time_unit unit){
  // Read which clocks in use, return half of the highest frequency in use in Hz for seconds, kHz for ms and MHz for us
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
  int freq = _get_osc_freq_halved(unit);

  // Find number of cycles needed to wait, and wait
  wait_cycles(freq * iSeconds);

  // Return
  return;
}

// Delays for given number of milliseconds
void delay_ms(int iMilliseconds){
    // Get highest frequency in use
    enum time_unit unit = millisecond;
    int freq = _get_osc_freq_halved(unit);

    // Find number of cycles needed to wait, and wait
    wait_cycles((freq * iMilliseconds));
  
    // Return
    return;
}

// Delays for given number of microseconds
void delay_us(int iMicroseconds){
  // Get highest frequency in use
  enum time_unit unit = microsecond;
  int freq = _get_osc_freq_halved(unit);

  // Find number of cycles needed to wait, and wait
  wait_cycles(freq * iMicroseconds);

  // Return
  return;
}

// MAIN FUNCTION
int main(void){
  // Set PIN PA20 as output
  set_pin_as_output(PA20);
  //*PORT_A_DIR_SET_ptr = *PORT_A_DIR_SET_ptr | 1 << 20;

  // Main loop
  while(1) {
    unsigned int n = 500;
    // Loop to fade in
    for(int i = 0; i<n ;i++){
      // Set PIN HIGH and test each delay
      register_bit_write_HIGH(PORT_A_OUT_SET, 20);
      delay_us(i);
  
      // Set PIN LOW
      set_pin_LOW(PA20);
      delay_us(n-i);
      }

    // Loop to fade out
    for(int i = 0; i<n ;i++){
      // Set PIN HIGH and test each delay
      set_pin_HIGH(PA20);
      delay_us(n - i);
  
      // Set PIN LOW
      set_pin_LOW(PA20);
      delay_us(i);
      }
  }
  return 0;
}