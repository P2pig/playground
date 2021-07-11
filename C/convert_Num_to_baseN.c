/*
 * Converts a number to a given base
 * eg. 8 to base 2  is 1000
 *   128 to base 16 is 80
 */

#include<stdio.h>

char* NumTobin(unsigned int num, int base)
{
    static char buff[33];
    char *ptr = &buff[sizeof(buff)-1];
    *ptr = '\0';
    do
    {
        *--ptr = "0123456789abcdef"[num %base];
        num /=base;
    }while(num!=0);
    return ptr;
}

int main()
{
    char *s;

    s=NumTobin(8, 2);
    printf("%s\n",s);

    s=NumTobin(128, 16);
    printf("%s\n",s);

    return 0;
}
