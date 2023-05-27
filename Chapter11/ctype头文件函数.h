//
// Created by Momo on 2023/5/27.
//

#ifndef MAIN_CPP_CTYPE头文件函数_H
#define MAIN_CPP_CTYPE头文件函数_H
#include <cstring>
#include <cstdio>
#include <cctype>
#include "字符串排序.h"

// 把字符转变成大写
void ToUpper(char * str);
// 统计字符串中标点符号的个数
int PunctCount(const char * str);


void main_function_1() {
    char arr[21], *p;
    int count;
    p = s_get(arr, 20);
    count = PunctCount(p);
    printf("标点符号数量是 %d 个\n", count);
    ToUpper(p);
    puts(p);
}


void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

int PunctCount(const char * str)
{
    int ct = 0;
    while (*str)
    {
        if (ispunct(*str))
            ct++;
        str++;
    }

    return ct;
}


#endif //MAIN_CPP_CTYPE头文件函数_H
