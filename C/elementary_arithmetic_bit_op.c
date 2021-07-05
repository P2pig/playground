#include <stdio.h>

int add(int a,int b);
int minus(int a, int b);
unsigned int multiply(unsigned int a, unsigned int b);
int divide(int a, int b);

int add(int a, int b) {
    /* Intuitive */
/*
    while(b != 0){
        int tmp = a^b;
        b = (a&b) << 1;
        a = tmp;
    }
*/
    /* recursive */
    if(b==0)
        return a;
    add(a^b, (a&b)<<1);
}

int minus(int a, int b) {
    add(a,-b);
}

unsigned int multiply(unsigned int a, unsigned int b) {
    unsigned int t = 0;

    while (b != 0) {
        if (b & 1)
            t = add(a,t);

        a <<= 1;
        b >>= 1;
    }
    return t;
}

int divide(int a, int b) {
    int tmp=1, ret=0;
    while(b<=a) { //MSB
        b<<=1;
        tmp<<=1;
    }
    while(tmp > 1) {
        b   >>= 1;
        tmp >>= 1;

        if(a >= b) {
            a = minus(a,b);
            ret = add(ret, tmp);
        }
    }
    return ret;
}

int main() {

    printf("100 + 100 = %d\n", add(100,100));
    printf("5 - 3 = %d\n", minus(5,3));
    printf("5 * -5 = %d\n", multiply(5,-5)); 
    printf("32 / 2 = %d\n", divide(32,2));

    return 0;
}

