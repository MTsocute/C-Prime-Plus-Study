//
// Created by Momo on 2023/5/5.
//

#ifndef MAIN_CPP_GET_PUT_CHAR_H
#define MAIN_CPP_GET_PUT_CHAR_H
#include <cstdio>
#include <cctype>       // 包含 isalpha() 函数
#define SPACE ' '


/* 所有非空格字母后退一个 */

void cypher() {
    char ch;
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch))        // 这个函数会判别是否是字符串
            putchar(ch + 1);
        else
            putchar(ch);
    }
}



#endif //MAIN_CPP_GET_PUT_CHAR_H
