//
// Created by Momo on 2023/6/21.
//

#ifndef C_LEARNING_预定义宏_H
#define C_LEARNING_预定义宏_H
// 预定义宏和预定义标识符
#include <cstdio>
#include <cstdlib>

void why_me();

void pre_define()
{
    printf("The file is %s.\n", __FILE__);      // 运行这个函数所在的具体文件
    printf("The date is %s.\n", __DATE__);      // 运行这个函数的具体日期（MM DD YY）
    printf("The time is %s.\n", __TIME__);      // 运行这个函数的时间 (HH: MM : SS)
    printf("This is line %d.\n", __LINE__);     // 展示当前代码所在的行
    printf("This function is %s\n", __func__);  // 展示所在的函数名
    printf("The version of C++ standard is %ldL\n", __cplusplus);
    puts("\n===================\n");
    why_me();
}

void why_me()
{
    printf("This function is %s\n", __func__);
    printf("This is line %d.\n", __LINE__);
}


// 使用 #error 改变报错 #line 改变行数和文件源
#if __cplusplus != 202002L
#line 123123 "你猜我在哪里.h"     // 当前行号和文件名重定义
// 重定义报错信息
#error NOT C++20
#endif

#endif //C_LEARNING_预定义宏_H
