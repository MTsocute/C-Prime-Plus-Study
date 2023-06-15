//
// Created by Momo on 2023/6/15.
//

#ifndef C_LEARNING_函数指针_H
#define C_LEARNING_函数指针_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define WORDS "I love you"

/** 函数指针的使用
    * (*p_func) 用于指向一个函数
 * 参数可有可无
    * (char * para) 接受一个参数
 * */

void (*p_func1)();              // 无参
void (*p_func2)(const char * para, int real);   // 有参


void some_func() {
    puts("hello world!");
}

void some_func_para(const char * para, int real) {
    puts(para);
    printf("The number is %d\n", real);
}


// 使用没有参数的函数指针
void use_pf_non_para() {
    p_func1 = some_func;
    (*p_func1)();       // 调用函数指针
}


// 使用有参数的函数指针
void use_of_para() {
    p_func2 = some_func_para;
    (*p_func2)(WORDS, 10);  // 调用函数指针（带参数）
}

void Toupper(char * str);

// 函数指针用于函数接受形参
void show(void(*prt)(char * strings), char *str) {
    (*prt)(str);    // 实现函数的间接调用
}

#endif //C_LEARNING_函数指针_H
