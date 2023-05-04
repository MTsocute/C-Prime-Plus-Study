//
// Created by Momo on 2023/5/2.
//

#ifndef MAIN_CPP_COMPARE_FLOAT_H
#define MAIN_CPP_COMPARE_FLOAT_H
#include <cstdio>
#include <cmath>

/* 浮点数的比较 */
void cmp_flt() {
    const double ANS = 3.14159;
    double rep;

    printf("What is the value of pi?\n");
    scanf("%lg", &rep);

    // 当用户输入的误差值 < 0.0001 就结束啦
    while (fabs(rep - ANS) > 0.0001)    // fabs() 绝对值函数
    {
        printf("Try again!\n");
        scanf("%lg", &rep);
    }
    printf("Close enough!\n");
}


#endif //MAIN_CPP_COMPARE_FLOAT_H
