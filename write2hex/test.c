// To test the program

#include <write2hex.h>
#include <stdio.h>

int main(){
    // byte
    char test1 = 13;
    printf("0x%02X\n", test1);
    write2hex(test1);

    // int
    int test2 = 130;
    printf("0x%02X\n", test2);
    write2hex(test2);
    
    // long
    long test3 = 1300;
    printf("0x%02X\n", test3);
    write2hex(test3);

    return 0;
}