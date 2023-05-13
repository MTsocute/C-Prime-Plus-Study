//
// Created by Momo on 2023/5/12.
//

#ifndef MAIN_CPP_POINTER_H
#define MAIN_CPP_POINTER_H
#include <cstdio>

void interchange(int u, int v);
void interchange_pointer(int * u, int * v);

// 地址运算符留给我们的思考
void interchange_problem()
{
    int x = 5, y = 10;
    printf("Originally x = %d and y = %d.\n", x, y);

    // 你会发现，我们在 interchange 内部实现了交换
    interchange(x, y);

    // 但是外部没有一点变化
    printf("Now x = %d and y = %d.\n", x, y);
}

// 利用指针解决这个赋值问题
void interchange_problem_solve()
{
    int x = 5, y = 10;
    printf("Originally x = %d and y = %d.\n", x, y);

    // 你会发现，我们在 interchange 内部实现了交换
    interchange_pointer(&x, &y);

    // 但是外部没有一点变化
    printf("Now x = %d and y = %d.\n", x, y);
}


/* 这里呢，我们这里的 u, v 就是外部的值传递
 * 相当于外部的 u 所在的地址 = x的值，v 同理
 * 而不是对 interchange_problem() 这个函数里面 x y 所在位置的值进行改变
 * */
void interchange(int u, int v)  // 传递过来给 u v 的 只是 x y 的值
{
    int temp;
    temp = u;
    u = v;
    v = temp;
}


/* 为了解决上面的问题，让我们来介绍下今天的主角，指针（Pointer） */
void interchange_pointer(int * u, int * v)  // 这个实现的就是地址之间值的转换，而不是创建了一个新变量接受
{
    int temp;
    temp = *u;    // temp获得 u 所指向对象的值
    *u = *v;
    *v = temp;
}

#endif //MAIN_CPP_POINTER_H
