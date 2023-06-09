//
// Created by Momo on 2023/5/12.
//

#ifndef MAIN_CPP_函数返回_H
#define MAIN_CPP_函数返回_H
#include <cstdarg>
#include <cstdio>


// 函数返回值可以是一个表达式的值
int imin(int a, int b) {
    return (a < b) ? a : b;
}

/**
 * 函数说明：计算两个整数的和
 *
 * 参数：
 *     a: 第一个整数
 *     b: 第二个整数
 *
 * 返回值：
 *     返回两个整数的和
 *
 * 异常情况：
 *     无异常情况
 *
 * 示例：
 *     int result = add(2, 3);  // result = 5
 */
int add_function(int a, int b) {
    return a + b;
}




// 返回值类型和定义函数类型不一样的时候
int what_if(int n) {
    double a = 100 / (double) n;
    return a;   // 这里会被强制转换成 int 类型
}


// 当形参数量不确定的时候，接受多个形参的方法
void printNumbers(int count, ...) {}



#endif //MAIN_CPP_函数返回_H
