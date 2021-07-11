/*
 * count leading zero
 * in base 2
 * Simply calculate numbers of 0's in higher bits 
 * and then subtract with 31
 */
#include <stdio.h>

int main() {
    int num = 8;
    int bit = 31;
    for(;;--bit) {
        if(num & 0x80000000) break;
        num <<= 1;
    }

    printf("No. of 0's: %d\n", 31-bit);

    return 0;
}
