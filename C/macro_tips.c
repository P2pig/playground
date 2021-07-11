/*
 * 介紹dangling else, 
 * 使用Macro技巧：_Generic, concatenate operator
 *
 * 來源： 你所不知道的 C 語言： 前置處理器應用篇
 * https://hackmd.io/@posutsai/Bkbrqe9jX?type=view
 */
#include <stdio.h>

#define PRINT_CONCAT(VALUE, TYPE)    \
         do {                     \
             print_ ## TYPE(VALUE);\
         } while(0)

#define PRINT_GENERIC(VALUE)    \
    _Generic((VALUE),           \
            float: print_float, \
            int:   print_int    \
            )(VALUE)

void print_float(float f){
    printf("float value is %f\n", f);
}
void print_int(int i){
    printf("int value is %i\n", i);
}

int main() {
    float f = 123.;
    int i = 10;
    PRINT_CONCAT(f, float);
    PRINT_CONCAT(i, int);

    PRINT_GENERIC(f);
    PRINT_GENERIC(i);

    return 0;
}

