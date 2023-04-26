//
// Created by Momo on 2023/4/25.
//

#ifndef MAIN_CPP_浮点数和修饰字符的组合_H
#define MAIN_CPP_浮点数和修饰字符的组合_H
#include <cstdio>

void float_and_MOD()
{
    const double RENT = 3852.99;  // const变量

    printf("*%f*\n", RENT);         // Default

    printf("*%e*\n", RENT);         // 转换成科学计数法
    printf("*%3.1f*\n", RENT);      // 前面整数部分只可以有3个，后面可以有1个，这里还造成了四舍五入，因为原来有两个只统计了一个

    printf("*%10.3f*\n", RENT);     // 前面有10个位置，不够的就填充，从右边开始
    printf("*%-10.3f*\n", RENT);    // 前面有10个位置，不够的就填充，从左边开始

    printf("*%10.3E*\n", RENT);     // 注意，科学记数法如果带有对宽度修饰符号，会对小数部分四舍五入

    printf("*%+4.2f*\n", RENT);     // 根据数正负对应显示
    printf("*%010.2f*\n", RENT);    // 如果前面有空，用 0 填充
}


#endif //MAIN_CPP_浮点数和修饰字符的组合_H
