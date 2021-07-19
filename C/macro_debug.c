/**
 * A cool macro for debug
 * Source: https://openhome.cc/Gossip/CGossip/Macro.html
 *
 *
 * #和## 在macro中的意思：
 *
 * 在巨集中表示其餘的項目，後續可以使用 __VA_ARGS__ 來代表；# 會將項目加上雙引號含括
 * 因此 #__VA_ARGS__ 的話，表示將其餘項目展開為字串。
 *
 * ## 的話是合併項目，例如若項目是 a 與 b，巨集中撰寫 ab 是不會分別展開的，因為項目必須
 * 使用空白區隔，這時可以撰寫 a##b，這麼一來，a 與 b 會分別展開後合併，
 * 例如若 a 為 12、b 為 34，那麼 a##b 就會是 1234。
 *
 * 如果 ## 出現在逗號之後，有些編譯器（例如 gcc）會在 __VAR_ARGS__ 為空時，
 * 自動移除逗號，上面的範例若將 ## 拿掉，debug 時若沒有指定 fmt 外的引數，
 * 展開後編譯就會出錯。
 * 
 *
 * C 語言本身預先定義了 __STDC__、__LINE__ 等名稱
 * https://en.cppreference.com/w/c/preprocessor/replace
 *
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
