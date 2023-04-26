//
// Created by Momo on 2023/4/25.
//

#ifndef MAIN_CPP_字符串_H
#define MAIN_CPP_字符串_H
# include <cstdio>
#include <cstring>

// 让我们来写一个输入名字，并对改对象打招呼的函数
void say_Hello() {
    char name[40];
    printf("What is your name?\n");
    scanf("%s", name);   // %s 来作为字符串的占位符号
    printf("Hello, Dear %s!\n", name);
    // 我们顺便再告诉人家他的名字有多少字（这里我们暂时不考虑空格的影响）
    printf("There are %zu letters in your name", strlen(name));
}

#endif //MAIN_CPP_字符串_H
