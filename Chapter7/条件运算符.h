//
// Created by Momo on 2023/5/7.
//

#ifndef MAIN_CPP_条件运算符_H
#define MAIN_CPP_条件运算符_H
#include <cstdio>

// ？ 三元运算符的使用
void condition_OP() {
    int x, y;
    printf("请为 y 赋值：");
    scanf("%d", &y);
    // True x = 25, False x = 52
    x = (y >= 0) ?  25 : 52;
    printf("x = %d", x);
}

// 实现上述同理的操作
void equal_condition_OP() {
    int x, y;
    printf("请为 y 赋值：");
    scanf("%d", &y);

    if (y >= 0)
        x = 25;
    if(y < 0)
        x = 52;

    printf("\nx = %d", x);
}

#endif //MAIN_CPP_条件运算符_H
