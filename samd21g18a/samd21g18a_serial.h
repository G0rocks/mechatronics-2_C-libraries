/*
samd21g18a_serial.h
Created by: Huldar
Date: 2025-03-03

Description:
This library contains functions for serial communication. Uses the SERCOM pheripheral
For use with the arduino MKR NB 1500 using the processor SAMD21G18A.
Datasheet: https://ww1.microchip.com/downloads/en/DeviceDoc/SAM_D21_DA1_Family_DataSheet_DS40001882F.pdf
*/

// Include guard
#ifndef _samd21g18a_serial_
#define _samd21g18a_serial_

//#include "samd21g18a_pointers.h"


// FUNCTIONS
//##############################################################

// USART enable
// SKOÐA BLAÐSÍÐU 78 Í file:///C:/Users/Huldar/Documents/Menntun/HR/Mechatronics%20II/Baldurs8bitCguide.pdf
void usart_enable() {
    // Before the USART is enabled, it must be configured by these steps:
    // 1. Select either external (0x0) or internal clock (0x1) by writing the Operating Mode value in the CTRLA register
    // (CTRLA.MODE).
    

    // 2. Select either asynchronous (0) or or synchronous (1) communication mode by writing the Communication
    // Mode bit in the CTRLA register (CTRLA.CMODE).
    
    // 3. Select pin for receive data by writing the Receive Data Pinout value in the CTRLA register (CTRLA.RXPO).

    // 4. Select pads for the transmitter and external clock by writing the Transmit Data Pinout bit in the CTRLA register
    // (CTRLA.TXPO).

    // 5. Configure the Character Size field in the CTRLB register (CTRLB.CHSIZE) for character size.

    // 6. Set the Data Order bit in the CTRLA register (CTRLA.DORD) to determine MSB- or LSB-first data
    // transmission.

    // 7. To use parity mode:
    // 7.1. Enable parity mode by writing 0x1 to the Frame Format field in the CTRLA register (CTRLA.FORM).

    // 7.2. Configure the Parity Mode bit in the CTRLB register (CTRLB.PMODE) for even or odd parity.

    // 8. Configure the number of stop bits in the Stop Bit Mode bit in the CTRLB register (CTRLB.SBMODE).

    // 9. When using an internal clock, write the Baud register (BAUD) to generate the desired baud rate.

    // 10. Enable the transmitter and receiver by writing '1' to the Receiver Enable and Transmitter Enable bits in the
    // CTRLB register (CTRLB.RXEN and CTRLB.TXEN).


}

#endif