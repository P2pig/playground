#include <stdio.h>
#include <string.h>

/*
 * Full adder (4 bits)
 * Example. 
 *      Adding:  0011
 *               0101
 *              ------
 *      Output:  1000
 */
int main(int argc, char *argv[]) {

    int A[4] = {0,0,1,1};
    int B[4] = {0,1,0,1};
    int sum[4];
    int carry=0;

    for(int i=3; i>=0; i--) {
        sum[i]=((A[i]^B[i])^carry);
        carry=((A[i]&B[i])|(A[i]&carry))|B[i]&carry;
    }

    for(int i=0;i<4;i++)
        printf("%d ", sum[i]);

    return 0;
}
