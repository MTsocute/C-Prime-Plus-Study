//
// Created by Momo on 2023/4/25.
//

#ifndef MAIN_CPP_占位符的修饰符号_H
#define MAIN_CPP_占位符的修饰符号_H
#include <cstdio>
#define PAGES 959

void MOD()
{
    printf("*%d*\n", PAGES);
    printf("*%2d*\n", PAGES);       // 虽然长度是2，但是要打印的有三个，所以挤满
    printf("*%10d*\n", PAGES);      // 默认从右边开始打印，而且 10d 说明整体宽度是 10
    printf("*%-10d*\n", PAGES);     // - 从左边开始打印边开始，而且 10d 说明整体宽度是 10
}

#endif //MAIN_CPP_占位符的修饰符号_H
