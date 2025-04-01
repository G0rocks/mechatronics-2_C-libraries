/*
samd21g18a_pointers.h
Created by: Huldar
Date: 2025-02-24

Description:
Pointers for use with the arduino MKR NB 1500 using the processor SAMD21G18A.
Datasheet: https://ww1.microchip.com/downloads/en/DeviceDoc/SAM_D21_DA1_Family_DataSheet_DS40001882F.pdf
*/

// Include guard
#ifndef _samd21g18a_pointers_
#define _samd21g18a_pointers_

#include "samd21g18a_registers.h"

// DEFINITIONS
// Format for register
// #define NAME ((register_type) {char num_bytes, 0xADDRESS) // Description
// Format for register pointer
// #define NAME_ptr ((unsigned char/short/int*) 0xADDRESS) // Description
//##############################################################
// AHB-APB Bridge A
//##############################################################


// PM - Power manager
//-------------------------------------
#define PM_ptr ((unsigned char*) 0x40000400) // See product mapping AHB-APB bridge A
#define PM ((unsigned int) 0x40000400) // See product mapping AHB-APB bridge A
#define PM_APBBMASK_ptr ((unsigned int*)(PM_ptr + 0x1C)) // APBBMASK register address, 16.8.9
#define PM_APBCMASK_ptr ((unsigned int*)(PM_ptr + 0x20)) // APBBMASK register address, 16.8.10
#define PM_APBCMASK ((register_type) {(unsigned char) 4, (unsigned int) (PM + 0x20)}) // APBBMASK register address, 16.8.10


// SYSCTRL - System Controller
//-------------------------------------
#define SYSCTRL_ptr ((unsigned char*) 0x40000800) // See product mapping, chap 9
#define SYSCTRL_INTENCLR_ptr ((unsigned int*) (SYSCTRL_ptr + 0x00)) // chap 17.8.1
#define SYSCTRL_INTENSET_ptr ((unsigned int*) (SYSCTRL_ptr + 0x04)) // chap 17.8.2
#define SYSCTRL_INTFLAG_ptr ((unsigned int*) (SYSCTRL_ptr + 0x08)) // chap 17.8.3
#define SYSCTRL_PCLKSR_ptr ((unsigned int*) (SYSCTRL_ptr + 0x0C)) // chap 17.8.4
#define SYSCTRL_XOSC_ptr ((unsigned short*) (SYSCTRL_ptr + 0x10)) // chap 17.8.5
#define SYSCTRL_XOSC32k_ptr ((unsigned short*) (SYSCTRL_ptr + 0x14)) // chap 17.8.6
#define SYSCTRL_OSC32K_ptr ((unsigned int*) (SYSCTRL_ptr + 0x18)) // chap 17.8.7
#define SYSCTRL_OSCULP32K_ptr ((unsigned char*) (SYSCTRL_ptr + 0x1C)) // chap 17.8.8
#define SYSCTRL_OSC8M_ptr ((unsigned int*) (SYSCTRL_ptr + 0x20)) // chap 17.8.9
#define SYSCTRL_OSC8M ((register_type) {(unsigned char) 4, (unsigned int)(SYSCTRL_OSC8M_ptr + 0x20)}) // chap 17.8.9
#define SYSCTRL_DFLLCTRL_ptr ((unsigned short*) (SYSCTRL_ptr + 0x24)) // chap 17.8.10
#define SYSCTRL_DFLLVAL_ptr ((unsigned int*) (SYSCTRL_ptr + 0x28)) // chap 17.8.11
#define SYSCTRL_DFLLMUL_ptr ((unsigned int*) (SYSCTRL_ptr + 0x2C)) // chap 17.8.12
#define SYSCTRL_DFLLSYNC_ptr ((unsigned char*) (SYSCTRL_ptr + 0x30)) // chap 17.8.13
#define SYSCTRL_BOD33_ptr ((unsigned int*) (SYSCTRL_ptr + 0x34)) // chap 17.8.14
#define SYSCTRL_VREG_ptr ((unsigned short*) (SYSCTRL_ptr + 0x3C)) // chap 17.8.15
#define SYSCTRL_VREF_ptr ((unsigned int*) (SYSCTRL_ptr + 0x40)) // chap 17.8.16
#define SYSCTRL_DPLLCTRLA_ptr ((unsigned char*) (SYSCTRL_ptr + 0x44)) // chap 17.8.17
#define SYSCTRL_DPLLRATIO_ptr ((unsigned int*) (SYSCTRL_ptr + 0x48)) // chap 17.8.18
#define SYSCTRL_DPLLCTRLB_ptr ((unsigned int*) (SYSCTRL_ptr + 0x4C)) // chap 17.8.19
#define SYSCTRL_STATUS_ptr ((unsigned char*) (SYSCTRL_ptr + 0x50)) // chap 17.8.20



//#define SYSCTRL_DFLL48M_ptr ((unsigned int*) (SYSCTRL_ptr + )) // chap 17.8.
//#define SYSCTRL_FDPLL96M_ptr ((unsigned int*) (SYSCTRL_ptr + )) // chap 17.8.

// GCLK - Generic Clock Controller
//-------------------------------------
#define GCLK_ptr ((unsigned char*) 0x40000C00)  // chapter 9 and 12
#define GCLK_STATUS_ptr ((unsigned int*) (GCLK_ptr + 0x1))   // 15.8.2
#define GCLK_CLKCTRL_ptr ((unsigned int*)(GCLK_ptr + 0x2))   // 15.8.3
#define GCLK_CLKCTRL ((register_type) {(unsigned char) 4, (unsigned int)(GCLK_ptr + 0x2)}) // chap 17.8.9
#define GCLK_GENCTRL_ptr ((unsigned int*)(GCLK_ptr + 0x4))   // 15.8.4

/// WTD - Watchdog timer
//-------------------------------------
#define WDT_ptr ((unsigned char*) 0x40001000) // Watchdog timer base address, chap 9, product mapping
#define WDT_CTRL ((register_type) {(unsigned char) 1, (unsigned int)(WDT_ptr + 0x00)}) // Control register, 18.8.1
#define WDT_CLEAR ((register_type) {(unsigned char) 1, (unsigned int)(WDT_ptr + 0x8)}) // Control register, 18.8.8
#define WDT_CLEAR_KEY 0xA5 // Key to clear watchdog timer, 18.8.8

//##############################################################
// AHB-APB Bridge B
//##############################################################

// PORT A - Configure peripheral port A, chapter 12 and 23.7, https://ww1.microchip.com/downloads/en/DeviceDoc/SAM_D21_DA1_Family_DataSheet_DS40001882F.pdf
#define PORT_A_ptr ((unsigned char*) 0x41004400) // PORT A base address, table 12-1
#define PORT_A ((unsigned int) 0x41004400) // PORT A base address, table 12-1
#define PORT_A_OFFSET ((unsigned int) 0x00)    // PORT A is 0x00 bytes away from PORT A
#define PORT_A_DIR_ptr  ((unsigned int*)(PORT_A_ptr)) // Pin direction register (input/output), 23.8.1
#define PORT_A_DIR_CLR ((register_type) {(unsigned char) 4, (unsigned int)(PORT_A + 0x04)}) // Output Clear Register, 23.8.6
#define PORT_A_DIR_SET_ptr  ((unsigned int*)(PORT_A_ptr + 0x08)) // Pin direction set register, 23.8.3
#define PORT_A_DIR_SET ((register_type) {(unsigned char) 4, (unsigned int)(PORT_A + 0x08)}) // Output Clear Register, 23.8.6
#define PORT_A_DIR_TGL ((register_type) {(unsigned char) 4, (unsigned int)(PORT_A + 0x0C)}) // Output Clear Register, 23.8.6
#define PORT_A_OUT_ptr ((unsigned int*)(PORT_A_ptr + 0x10))     // Output register, 23.8.5 for PORT A
#define PORT_A_OUT_CLR_ptr ((unsigned int*)(PORT_A_ptr + 0x14)) // Output Clear Register, 23.8.6
#define PORT_A_OUT_CLR ((register_type) {(unsigned char) 4, (unsigned int)(PORT_A + 0x14)}) // Output Clear Register, 23.8.6
#define PORT_A_OUT_SET_ptr ((unsigned int*) (PORT_A_ptr  + 0x18)) // Output Set Register, 23.8.7
#define PORT_A_OUT_SET ((register_type) {(unsigned char) 4, (unsigned int)(PORT_A + 0x18)}) // APBBMASK register address, 16.8.10
#define PORT_A_IN ((register_type) {(unsigned char) 4, (unsigned int)(PORT_A + 0x20)}) // 23.8.9
#define PORT_A_PMUX_PINS_0_1 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x30)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_2_3 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x31)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_4_5 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x32)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_6_7 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x33)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_8_9 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x34)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_10_11 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x35)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_12_13 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x36)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_14_15 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x37)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_16_17 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x38)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_18_19 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x39)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_20_21 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x3A)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_22_23 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x3B)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_24_25 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x3C)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_26_27 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x3D)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_28_29 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x3E)}) // Peripheral Multiplexing, 23.8.12
#define PORT_A_PMUX_PINS_30_31 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A + 0x3F)}) // Peripheral Multiplexing, 23.8.12

#define PORT_A_PINCFG_ptr ((unsigned int*)(PORT_A_ptr  + 0x40)) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN0 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x00)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN1 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x01)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN2 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x02)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN3 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x03)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN4 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x04)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN5 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x05)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN6 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x06)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN7 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x07)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN8 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x08)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN9 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x09)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN10 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x0A)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN11 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x0B)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN12 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x0C)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN13 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x0D)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN14 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x0E)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN15 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x0F)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN16 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x10)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN17 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x11)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN18 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x12)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN19 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x13)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN20 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x14)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN21 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x15)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN22 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x16)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN23 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x17)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN24 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x18)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN25 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x19)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN26 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x1A)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN27 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x1B)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN28 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x1C)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN29 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x1D)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN30 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x1E)}) // Pin Configuration Register, 23.8.13
#define PORT_A_PINCFG_PIN31 ((register_type) {(unsigned char) 1, (unsigned int)(PORT_A_ptr  + 0x40 + 0x1F)}) // Pin Configuration Register, 23.8.13

// PORT B
#define PORT_B_offset ((unsigned int) 0x80) // PORT B is 0x80 bytes away from PORT A
//#define PORT_B_DIR_ptr  ((unsigned int*) PORT_A_DIR_ptr + PORT_B_spacing) // Chap, 23.8.1
//#define PORT_B_DIR_SET_ptr ((unsigned int*)  PORT_A_DIR_SET_ptr + PORT_B_spacing) // Pin direction set register, 23.8.3
//#define PORT_B_OUT_ptr ((unsigned int*)  PORT_A_OUT_ptr + PORT_B_spacing)      // Output register, 23.8.5 for PORT A
//#define PORT_B_OUT_CLR_ptr ((unsigned int*)  PORT_A_OUT_CLR_ptr + PORT_B_spacing) // Output Clear Register, 23.8.6
//#define PORT_B_OUT_SET_ptr ((unsigned int*)  PORT_A_OUT_SET_ptr + PORT_B_spacing) // Output Set Register, 23.8.7
//#define PORT_B_PINCFG_ptr  ((unsigned int*)  PORT_A_PINCFG_ptr + PORT_B_spacing) // Pin Configuration Register, 23.8.13

// USB - Universal Serial Bus, chapter 32
#define USB ((unsigned int) 0x41005000) // USB base address, chap. 9 product mapping


//##############################################################
// AHB-APB Bridge C
//##############################################################

// PAC OFFSETS- Peripheral Access Controller, chapter 11.6
#define PAC_WPCLR_OFFSET ((unsigned int) 0x00) // Write protection clear register,
#define PAC_WPSET_OFFSET ((unsigned int) 0x04) // Write protection set register,

// PAC0 - Peripheral Access Controller 0, chapter 11.6
#define PAC0 ((unsigned int) 0x40000000) // See product mapping AHB-APB bridge C.
#define PAC0_ptr ((unsigned char*) PAC0) // See product mapping AHB-APB bridge C.
#define PAC0_WPCLR ((register_type) {(unsigned char) 4, (unsigned int) (PAC0 + PAC_WPCLR_OFFSET)}) // Write protection clear register, 11.6.2.1.1
#define PAC0_WPSET ((register_type) {(unsigned char) 4, (unsigned int) (PAC0 + PAC_WPSET_OFFSET)}) // Write protection set register, 11.6.2.1.2

// PAC1 - Peripheral Access Controller 1, chapter 11.6
#define PAC1 ((unsigned int) 0x41000000) // See product mapping AHB-APB bridge C.
#define PAC1_ptr ((unsigned char*) PAC1) // See product mapping AHB-APB bridge C.
#define PAC1_WPCLR ((register_type) {(unsigned char) 4, (unsigned int) (PAC1 + PAC_WPCLR_OFFSET)}) // Write protection clear register, 11.6.2.2.1
#define PAC1_WPSET ((register_type) {(unsigned char) 4, (unsigned int) (PAC1 + PAC_WPSET_OFFSET)}) // Write protection set register, 11.6.2.2.2

// PAC2 - Peripheral Access Controller 2, chapter 11.6
#define PAC2 ((unsigned int) 0x42000000) // See product mapping AHB-APB bridge C.
#define PAC2_ptr ((unsigned char*) PAC2) // See product mapping AHB-APB bridge C.
#define PAC2_WPCLR ((register_type) {(unsigned char) 4, (unsigned int) (PAC2 + PAC_WPCLR_OFFSET)}) // Write protection clear register, 11.6.2.3.1
#define PAC2_WPSET ((register_type) {(unsigned char) 4, (unsigned int) (PAC2 + PAC_WPSET_OFFSET)}) // Write protection set register, 11.6.2.3.2


// SERCOM OFFSETS- Serial Communication Interface, chapter 25
#define SERCOM_CTRLA_OFFSET ((unsigned int) 0x00) // Control A register, 26.7
#define SERCOM_CTRLB_OFFSET ((unsigned int) 0x04) // Control B register, 26.7
#define SERCOM_BAUD_OFFSET ((unsigned int) 0x0C) // Baud rate register, 26.7
#define SERCOM_RXPL_OFFSET ((unsigned int) 0x0E) // Receive pulse length register, 26.7
#define SERCOM_INTENCLR_OFFSET ((unsigned int) 0x14) // Interrupt enable clear register, 26.7
#define SERCOM_INTENSET_OFFSET ((unsigned int) 0x16) // Interrupt enable set register, 26.7
#define SERCOM_INTFLAG_OFFSET ((unsigned int) 0x18) // Interrupt flag status and clear register, 26.7
#define SERCOM_STATUS_OFFSET ((unsigned int) 0x1A) // Status register, 26.7
#define SERCOM_SYNCBUSY_OFFSET ((unsigned int) 0x1C) // Synchronization busy register, 26.7
#define SERCOM_DATA_OFFSET ((unsigned int) 0x28) // Data register, 26.7
#define SERCOM_DBGCTRL_OFFSET ((unsigned int) 0x30) // Debug control register, 26.7

// SERCOM0 - Serial Communication Interface 3, chapter 25
#define SERCOM0 ((unsigned int) 0x42000800) // See product mapping AHB-APB bridge C.
#define SERCOM0_ptr ((unsigned char*) SERCOM0) // See product mapping AHB-APB bridge C.
#define SERCOM0_CTRLA ((register_type) {(unsigned char) 4, (unsigned int)(SERCOM0 + SERCOM_CTRLA_OFFSET)}) // Output Clear Register, 23.8.6
#define SERCOM0_CTRLB ((register_type) {(unsigned char) 4, (unsigned int) (SERCOM0 + SERCOM_CTRLB_OFFSET)}) // Control B register, 26.7
#define SERCOM0_BAUD ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM0 + SERCOM_BAUD_OFFSET)}) // Baud rate register, 26.7
#define SERCOM0_RXPL ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM0 + SERCOM_RXPL_OFFSET)}) // Receive pulse length register, 26.7
#define SERCOM0_INTENCLR ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM0 + SERCOM_INTENCLR_OFFSET)}) // Interrupt enable clear register, 26.7
#define SERCOM0_INTENSET ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM0 + SERCOM_INTENSET_OFFSET)}) // Interrupt enable set register, 26.7
#define SERCOM0_INTFLAG ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM0 + SERCOM_INTFLAG_OFFSET)}) // Interrupt flag status and clear register, 26.7
#define SERCOM0_STATUS ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM0 + SERCOM_STATUS_OFFSET)}) // Status register, 26.7
#define SERCOM0_SYNCBUSY ((register_type) {(unsigned char) 4, (unsigned int) (SERCOM0 + SERCOM_SYNCBUSY_OFFSET)}) // Synchronization busy register, 26.7
#define SERCOM0_DATA ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM0 + SERCOM_DATA_OFFSET)}) // Data register, 26.7
#define SERCOM0_DBGCTRL ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM0 + SERCOM_DBGCTRL_OFFSET)}) // Debug control register, 26.7

// SERCOM1 - Serial Communication Interface 3, chapter 25
#define SERCOM1 ((unsigned int) 0x42000800) // See product mapping AHB-APB bridge C.
#define SERCOM1_ptr ((unsigned char*) SERCOM1) // See product mapping AHB-APB bridge C.
#define SERCOM1_CTRLA ((register_type) {(unsigned char) 4, (unsigned int)(SERCOM1 + SERCOM_CTRLA_OFFSET)}) // Output Clear Register, 23.8.6
#define SERCOM1_CTRLB ((register_type) {(unsigned char) 4, (unsigned int) (SERCOM1 + SERCOM_CTRLB_OFFSET)}) // Control B register, 26.7
#define SERCOM1_BAUD ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM1 + SERCOM_BAUD_OFFSET)}) // Baud rate register, 26.7
#define SERCOM1_RXPL ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM1 + SERCOM_RXPL_OFFSET)}) // Receive pulse length register, 26.7
#define SERCOM1_INTENCLR ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM1 + SERCOM_INTENCLR_OFFSET)}) // Interrupt enable clear register, 26.7
#define SERCOM1_INTENSET ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM1 + SERCOM_INTENSET_OFFSET)}) // Interrupt enable set register, 26.7
#define SERCOM1_INTFLAG ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM1 + SERCOM_INTFLAG_OFFSET)}) // Interrupt flag status and clear register, 26.7
#define SERCOM1_STATUS ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM1 + SERCOM_STATUS_OFFSET)}) // Status register, 26.7
#define SERCOM1_SYNCBUSY ((register_type) {(unsigned char) 4, (unsigned int) (SERCOM1 + SERCOM_SYNCBUSY_OFFSET)}) // Synchronization busy register, 26.7
#define SERCOM1_DATA ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM1 + SERCOM_DATA_OFFSET)}) // Data register, 26.7
#define SERCOM1_DBGCTRL ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM1 + SERCOM_DBGCTRL_OFFSET)}) // Debug control register, 26.7

// SERCOM2 - Serial Communication Interface 3, chapter 25
#define SERCOM2 ((unsigned int) 0x42000800) // See product mapping AHB-APB bridge C.
#define SERCOM2_ptr ((unsigned char*) SERCOM2) // See product mapping AHB-APB bridge C.
#define SERCOM2_CTRLA ((register_type) {(unsigned char) 4, (unsigned int)(SERCOM2 + SERCOM_CTRLA_OFFSET)}) // Output Clear Register, 23.8.6
#define SERCOM2_CTRLB ((register_type) {(unsigned char) 4, (unsigned int) (SERCOM2 + SERCOM_CTRLB_OFFSET)}) // Control B register, 26.7
#define SERCOM2_BAUD ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM2 + SERCOM_BAUD_OFFSET)}) // Baud rate register, 26.7
#define SERCOM2_RXPL ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM2 + SERCOM_RXPL_OFFSET)}) // Receive pulse length register, 26.7
#define SERCOM2_INTENCLR ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM2 + SERCOM_INTENCLR_OFFSET)}) // Interrupt enable clear register, 26.7
#define SERCOM2_INTENSET ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM2 + SERCOM_INTENSET_OFFSET)}) // Interrupt enable set register, 26.7
#define SERCOM2_INTFLAG ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM2 + SERCOM_INTFLAG_OFFSET)}) // Interrupt flag status and clear register, 26.7
#define SERCOM2_STATUS ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM2 + SERCOM_STATUS_OFFSET)}) // Status register, 26.7
#define SERCOM2_SYNCBUSY ((register_type) {(unsigned char) 4, (unsigned int) (SERCOM2 + SERCOM_SYNCBUSY_OFFSET)}) // Synchronization busy register, 26.7
#define SERCOM2_DATA ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM2 + SERCOM_DATA_OFFSET)}) // Data register, 26.7
#define SERCOM2_DBGCTRL ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM2 + SERCOM_DBGCTRL_OFFSET)}) // Debug control register, 26.7

// SERCOM3 - Serial Communication Interface 3, chapter 25
#define SERCOM3 ((unsigned int) 0x42000800) // See product mapping AHB-APB bridge C.
#define SERCOM3_ptr ((unsigned char*) SERCOM3) // See product mapping AHB-APB bridge C.
#define SERCOM3_CTRLA ((register_type) {(unsigned char) 4, (unsigned int)(SERCOM3 + SERCOM_CTRLA_OFFSET)}) // Output Clear Register, 23.8.6
#define SERCOM3_CTRLB ((register_type) {(unsigned char) 4, (unsigned int) (SERCOM3 + SERCOM_CTRLB_OFFSET)}) // Control B register, 26.7
#define SERCOM3_BAUD ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM3 + SERCOM_BAUD_OFFSET)}) // Baud rate register, 26.7
#define SERCOM3_RXPL ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM3 + SERCOM_RXPL_OFFSET)}) // Receive pulse length register, 26.7
#define SERCOM3_INTENCLR ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM3 + SERCOM_INTENCLR_OFFSET)}) // Interrupt enable clear register, 26.7
#define SERCOM3_INTENSET ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM3 + SERCOM_INTENSET_OFFSET)}) // Interrupt enable set register, 26.7
#define SERCOM3_INTFLAG ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM3 + SERCOM_INTFLAG_OFFSET)}) // Interrupt flag status and clear register, 26.7
#define SERCOM3_STATUS ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM3 + SERCOM_STATUS_OFFSET)}) // Status register, 26.7
#define SERCOM3_SYNCBUSY ((register_type) {(unsigned char) 4, (unsigned int) (SERCOM3 + SERCOM_SYNCBUSY_OFFSET)}) // Synchronization busy register, 26.7
#define SERCOM3_DATA ((register_type) {(unsigned char) 2, (unsigned int) (SERCOM3 + SERCOM_DATA_OFFSET)}) // Data register, 26.7
#define SERCOM3_DBGCTRL ((register_type) {(unsigned char) 1, (unsigned int) (SERCOM3 + SERCOM_DBGCTRL_OFFSET)}) // Debug control register, 26.7



// TC3 - Timer Counter 3, chapter 30
#define TC3 ((unsigned int)  0x42002C00) // See product mapping AHB-APB bridge C.
#define TC3_ptr ((unsigned char*) 0x42002C00) // See product mapping AHB-APB bridge C.
#define TC3_CTRLA ((register_type) {(unsigned char) 2, (unsigned int) (TC3 + 0x00)}) // Control A register, 30.8.1


// ADC - Analog to Digital Converter, chapter 33
#define ADC ((unsigned char) 0x42004000) // See product mapping AHB-APB bridge C.
#define ADC_ptr ((unsigned char*) 0x42004000) // See product mapping AHB-APB bridge C.
#define ADC_CTRLA ((register_type) {(unsigned char) 1, (unsigned int) (ADC + 0x00)}) // Control A register, 33.8.1
#define ADC_STATUS ((register_type) {(unsigned char) 1, (unsigned int) (ADC + 0x19)}) // 33.8.13


#endif // _samd21g18a_pointers_