/*
 * A cool macro for debug
 * Source: https://openhome.cc/Gossip/CGossip/Macro.html
 */
#define __DEBUG__

#include <stdio.h>

#define debug(fmt, ...) { \
        fprintf(stderr, "(%s:%d) "fmt"\n", __FILE__, __LINE__, ##__VA_ARGS__); \
}

int main(void) {

#ifdef __DEBUG__
        debug("%s %d", "Shit happen!", 1);
#endif

            return 0;
}
