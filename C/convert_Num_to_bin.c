/*
 * print binary equivalent to num
 */
#include<stdio.h>

int main()
{
    unsigned int num;
    int i;
    printf("input a number: ");
    scanf("%u", &num);
    for(i=0; i<16; i++)
    {
        printf("%d", (num<<i & 1<<15)?1:0);
    }
    return 0;
}
