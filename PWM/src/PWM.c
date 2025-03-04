/*
PWM.c
Created by: Huldar
Date: 2025-02-24
For homework 4 in mechatronics 2 spring 2025

NOTE: DOES NOT CURRENTLY WORK

Description:
PWM control for pins.
For use with the arduino MKR NB 1500 using the processor SAMD21G18A.
Datasheet: https://ww1.microchip.com/downloads/en/DeviceDoc/SAM_D21_DA1_Family_DataSheet_DS40001882F.pdf
*/

//#include "../../delay/src/delay.h"    // delay functions
#include "../../samd21g18a/samd21g18a_pointers.h" // SAMD21G18A pointers
#include "../../samd21g18a/samd21g18a_registers.h" // SAMD21G18A registers
#include "../../samd21g18a/samd21g18a_pins.h" // SAMD21G18A pins


void set_pin_as_PWM_output(pin p) {
  // Sets the pin as PWM output, based on chapter 30.6.2.1 Initialization of the SAMD21G18A datasheet
  // p: pin struct
  // To enable the TC, the following steps must be performed:
  // 1. Enable the TC3 bus clock (CLK_TCx_APB) in the PM, see chap. 16.6.2.6
  // Bit 11 – TC3 APB Clock Enable
  register_bit_write_HIGH(PM_APBCMASK, 11);

  // 2. Select 8-, 16- or 32-bit counter mode via the TC Mode bit group in the Control A register (CTRLA.MODE). The
  // default mode is 16-bit.
  register_bits_write(TC3_CTRLA, 2, 2, 0); // 16-bit counter mode. TC3_CTRLA_MODE = 0b00


  // 3. Select one wave generation operation in the Waveform Generation Operation bit group in the Control A
  // register (CTRLA.WAVEGEN).

  // 4. If desired, the GCLK_TCx clock can be prescaled via the Prescaler bit group in the Control A register
  // (CTRLA.PRESCALER).
  // – If the prescaler is used, select a prescaler synchronization operation via the Prescaler and Counter
  // Synchronization bit group in the Control A register (CTRLA.PRESYNC).

  // 5. Select one-shot operation by writing a '1' to the One-Shot bit in the Control B Set register
  // (CTRLBSET.ONESHOT).

  // 6. If desired, configure the counting direction 'down' (starting from the TOP value) by writing a '1' to the Counter
  // Direction bit in the Control B register (CTRLBSET.DIR).

  // 7. For capture operation, enable the individual channels to capture in the Capture Channel x Enable bit group in
  // the Control C register (CTRLC.CPTEN).

  // 8. If desired, enable inversion of the waveform output or IO pin input signal for individual channels via the
  // Waveform Output Invert Enable bit group in the Control C register (CTRLC.INVEN

}

void pwm(int duty_cycle, pin p){
  // Sets the duty cycle of the PWM signal to the given pin. Make sure the pin is already configured as a PWM output
  // duty_cycle: 0-100
  // p: pin struct
  /*
  // Check duty_cycle
  if (duty_cycle < 0 || duty_cycle > 100) {
    return;
  }

  // Find port address
  unsigned int* port_address_out_set = PORT_A_OUT_SET_ptr;
  unsigned int* port_address_out_clear = PORT_A_OUT_CLR_ptr;

  // If PORT B add the offset
  if (p.port == B) {
    port_address_out_set = port_address_out_set + PORT_B_spacing;
    port_address_out_clear = port_address_out_clear + PORT_B_spacing;
  }

  // Set PIN HIGH
  *port_address_out_set = *port_address_out_set | 1 << p.pin_number;
  wait_cycles(duty_cycle); // Waits twice as many clock cycles

  // Set PIN LOW
  *port_address_out_clear = *port_address_out_clear | 1 << p.pin_number;
  //wait_cycles(100 - duty_cycle);
  */
}


// void fade()


// MAIN FUNCTION
int main(void){
  // Set PA20 as PWM output
  set_pin_as_output(PA20);
  //set_pin_as_pwm_output(PA20);

  // Main loop
  while(1) {
    // Set PWM
    //pwm(50, PA20);
    // Set PIN HIGH and test each delay
    //register_bits_write(PORT_A_OUT_SET, 20, 1, 1);
    //set_pin_HIGH(PA20);
    //delay_s(1);

    // Set PIN LOW
    //register_bit_write_HIGH(PORT_A_OUT_CLR, 20);
    //delay_s(1);
  }
  return 0;
}