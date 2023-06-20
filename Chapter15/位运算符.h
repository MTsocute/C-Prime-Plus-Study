//
// Created by Momo on 2023/6/16.
//

#ifndef C_LEARNING_位运算符_H
#define C_LEARNING_位运算符_H
#include <cstdlib>
#include <cstdio>

/* 就是对二进制数据的逻辑运算 */


// 取反: 这里是有符号数，所以取反是负数
void bit_inverse() {
    int val = 0b00000010;       // 二进制数

    printf("val = %d\n", val);
    printf("~val = %d\n", ~val);
}

// 与计算: 都是 1 才是 1
void and_operate() {
    unsigned int val1 = 0b10010011;
    unsigned int val2 = 0b00111101;
    // ---> 0011 | 0001 = 17
    printf("And operate value is %d\n", val1&val2);
}


#endif //C_LEARNING_位运算符_H
