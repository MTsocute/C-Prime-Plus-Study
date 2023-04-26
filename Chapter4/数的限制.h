//
// Created by Momo on 2023/4/25.
//

#ifndef MAIN_CPP_数的限制_H
#define MAIN_CPP_数的限制_H
#include <cstdio>


#include <cfloat>   // 整数的限制
#include <climits>  // 浮点数的限制

void LIM() {
    printf("Some number limits for this system:\n");
    printf("Biggest int: %d\n", INT_MAX);   // 最大的整数
    printf("Smallest long long: %lld\n", LLONG_MIN);    // 最小的 longlong 整数
    printf("One byte = %d bits on this system.\n", CHAR_BIT);   // 系统规定一个直接占多少位
    printf("Largest double: %e\n", DBL_MAX);    // 最大的 double
    printf("Smallest normal float: %e\n", FLT_MIN);     // 最小的 float
    printf("float precision = %d digits\n", FLT_DIG);   // 浮点数最精确能精确到几位
    printf("float epsilon = %e\n", FLT_EPSILON);    // 输出浮点数的极小数
}

#endif //MAIN_CPP_数的限制_H
