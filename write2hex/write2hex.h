/*
* write2hex.h
* Created by: Huldar
* Date: 2025-02-23
* For homework 6 in mechatronics 2 spring 2025
* Description:
* Program can write a byte, int and long to terminal program in ASCII hex format
* e.g. for a byte with value 13D (13 in decimal) we would get „0x0D“
*/

// Include guard
#ifndef _write2hex_
#define _write2hex_

// write2hex exists for byte, int and long
void char2hex(char c);
void int2hex(int i);
void long2hex(long l);

#endif // _2hex_