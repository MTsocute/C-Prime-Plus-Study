//
// Created by Momo on 2023/5/8.
//

#ifndef MAIN_CPP_EOF_H
#define MAIN_CPP_EOF_H
#include <cstdio>

// 演示 EOF 在文件中的使用
void EOF_demo() {
    int ch;
    /* 注意是 int 而不是 char
     * getchar() 的返回值是一个 int
     * */
    while ((ch = getchar()) != EOF) // ctrl + D 结束
        putchar(ch);
}

#endif //MAIN_CPP_EOF_H
