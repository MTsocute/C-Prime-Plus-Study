//
// Created by Momo on 2023/6/16.
//

#ifndef C_LEARNING_位移运算符_H
#define C_LEARNING_位移运算符_H
#include <cstdio>
#include <cstdlib>
#include <climits>

// 左移运算符
void bit_move_left() {
    int val = 1;
    int stoke = val << 2;   // 整体二进制往左移动两位，空出来的位置用 0 填充
    printf("The value of stoke is %d\n", stoke);

    // 更简单的写法
    int val2 = 1;
    printf("The value of stoke2 is %d\n", val2<<=2);
}

// 右移运算符
void bit_move_right() {
    unsigned int val = 0b10001010;
    val >>= 2;

    printf("val = %d", val);
}


// 利用位运算，实现 int --> bin
char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}

#endif //C_LEARNING_位移运算符_H
