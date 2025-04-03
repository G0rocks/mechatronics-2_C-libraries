
#include <delay.h>
#include <samd21g18a_blinker.h>
#include <samd21g18a_registers.h>
#include <samd21g18a_pointers.h>
#include <samd21g18a_pins.h>

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