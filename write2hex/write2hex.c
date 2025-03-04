/*
* 2hex.c
* Created by: Huldar
* Date: 2025-02-23
* For homework 6 in mechatronics 2 spring 2025
* Description:
* Program can write a byte, int and long to terminal program in ASCII hex format
* e.g. for a byte with value 13D (13 in decimal) we would get „0x0D“
*/

#include "write2hex.h"
#include <stdio.h>


// write2hex exists for byte (char), int and long
void char2hex(char c) {
    printf("0x%02X\n", c);
}

void int2hex(int i){
    printf("0x%02X\n", i);
}

void long2hex(long l){
    printf("0x%02X\n", l);
}