#include <stdio.h>
#include <string.h>

/*
 * 3 differnt ways of swap in macro:
 * swap1 - using gcc extention typeof
 * swap2 - using gcc-specifice extensinos
 * sawp3 - using memcpy function in string.h
 */

#define swap1(a,b,T) do { T t=a; a=b; b=t; } while (0);
#define swap2(a,b)   do { typeof(a) t=a; a=b; b=t; } while (0);
#define swap3(a,b)   do {                               \
    unsigned char t[sizeof(a)==sizeof(b)?sizeof(a):-1]; \
    memcpy(t, &a, sizeof(a));                           \
    memcpy(&a, &b, sizeof(a));                          \
    memcpy(&b, t, sizeof(a));                           \
} while (0);

int main(int argc, char *argv[]) {
    int a = 2;
    int b = 3;

    swap1(a,b,int); printf("a: %d, b: %d\n", a,b);
    swap2(a,b);     printf("a: %d, b: %d\n", a,b);
    swap3(a,b);     printf("a: %d, b: %d\n", a,b);

    return 0;
}
