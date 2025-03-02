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

// DEFINITIONS
//##############################################################
// AHB-APB Bridge A
//##############################################################


// PM - Power manager
//-------------------------------------
#define PM_ptr ((unsigned char*) 0x40000400) // See product mapping AHB-APB bridge A. Chapter 16.8.9 on the APBB Mask (Port A is on bridge B on APB, chapter 9), the clock to the PORT is ENABLED by default.
#define PM_APBBMASK_ptr ((unsigned int*)(PM_ptr + 0x1C)) // APBBMASK register address, 16.8.9


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
#define GCLK_GENCTRL_ptr ((unsigned int*)(GCLK_ptr + 0x4))   // 15.8.4

//##############################################################
// AHB-APB Bridge B
//##############################################################

// PORT A - Configure peripheral port A, chapter 12 and 23.7, https://ww1.microchip.com/downloads/en/DeviceDoc/SAM_D21_DA1_Family_DataSheet_DS40001882F.pdf
#define PORT_A_ptr ((unsigned char*) 0x41004400) // PORT A base address, table 12-1
#define PORT_A_OFFSET ((unsigned int) 0x00)    // PORT A is 0x00 bytes away from PORT A
#define PORT_A_DIR_ptr  ((unsigned int*)(PORT_A_ptr)) // Pin direction register (input/output), 23.8.1
#define PORT_A_DIR_SET_ptr  ((unsigned int*)(PORT_A_ptr + 0x08)) // Pin direction set register, 23.8.3
#define PORT_A_OUT_ptr ((unsigned int*)(PORT_A_ptr  + 0x10))     // Output register, 23.8.5 for PORT A
#define PORT_A_OUT_CLR_ptr ((unsigned int*)(PORT_A_ptr  + 0x14)) // Output Clear Register, 23.8.6
#define PORT_A_OUT_SET_ptr ((unsigned int*) (PORT_A_ptr  + 0x18)) // Output Set Register, 23.8.7
#define PORT_A_PINCFG_ptr ((unsigned int*)(PORT_A_ptr  + 0x40)) // Pin Configuration Register, 23.8.13
// PORT B
#define PORT_B_offset ((unsigned int) 0x80) // PORT B is 0x80 bytes away from PORT A
//#define PORT_B_DIR_ptr  ((unsigned int*) PORT_A_DIR_ptr + PORT_B_spacing) // Chap, 23.8.1
//#define PORT_B_DIR_SET_ptr ((unsigned int*)  PORT_A_DIR_SET_ptr + PORT_B_spacing) // Pin direction set register, 23.8.3
//#define PORT_B_OUT_ptr ((unsigned int*)  PORT_A_OUT_ptr + PORT_B_spacing)      // Output register, 23.8.5 for PORT A
//#define PORT_B_OUT_CLR_ptr ((unsigned int*)  PORT_A_OUT_CLR_ptr + PORT_B_spacing) // Output Clear Register, 23.8.6
//#define PORT_B_OUT_SET_ptr ((unsigned int*)  PORT_A_OUT_SET_ptr + PORT_B_spacing) // Output Set Register, 23.8.7
//#define PORT_B_PINCFG_ptr  ((unsigned int*)  PORT_A_PINCFG_ptr + PORT_B_spacing) // Pin Configuration Register, 23.8.13

//##############################################################
// AHB-APB Bridge C
//##############################################################


#endif // _samd21g18a_pointers_