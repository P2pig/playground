#include <stdio.h>

int add(int a,int b);
int minus(int a, int b);
int multiply(int a, int b);
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

int main() {

    printf("100 + 100 = %d\n", add(100,100));

    return 0;
}
