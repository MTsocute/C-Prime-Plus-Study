//
// Created by Momo on 2023/5/12.
//

#ifndef MAIN_CPP_地址运算符_H
#define MAIN_CPP_地址运算符_H
#include <cstdio>
void interchange(int u, int v); /* 声明函数 */

/* 你会发现两个地址都不一样 */

void ts02(int);

// 不同函数中的同名变量存储地址和传递
void ts01() {
    int a = 5, b = 2;
    printf("a in ts01 = %p\n", &a);
    printf("b in ts01 = %p\n", &b);
    ts02(b);    // 这种传递就是值传递，不会
}

void ts02(int b)    // int b(ts02) = b(ts01) 就是值传递而不是地址
{
    int a = 2;
    printf("a in ts02 = %p\n", &a);
    printf("b in ts02 = %p\n", &b);
}

#endif //MAIN_CPP_地址运算符_H
