//
// Created by Momo on 2023/5/20.
//

#ifndef MAIN_CPP_指针的兼容性_H
#define MAIN_CPP_指针的兼容性_H
#include <cstdio>

void detail_of_pointer() {
    int * pt;
    int (*pa)[3];
    int ar1[2][3];
    int ar2[3][2];
    int **p2;    // 一个指向指针的指针

    // &ar1[0][0] 是第一个数组下第一个数组的地址，指针指向的是一个地址
    pt = &ar1[0][0];
    // ar1[0] 是数组中第一数组的首地址，指针自然也是可以指向的
    pt = ar1[0];
    // 一维的指针无法指向二维的地址
    pt = ar1;           /* 无效 */

    // 多维数组指针可以指向对应的地址
    pa = ar1;
    // 但是要注意声明的指针的维数和多维数组子空间数组数量相同
    pa = ar2;           /* 无效 */

    // 二维指针指向一维指针，指向指针的指针
    p2 = &pt;
    // *p2 存储一个指针的地址
    *p2 = ar2[0];
    // 虽然是二维指针，但是不可以用这种方式指向多维数组
    p2 = ar2;           /* 无效 */
}

// const指针 和 非const指针 赋值问题
void multi_pointer_safe() {
    int x = 20;
    const int y = 23;

    int * p1 = &x;          // 非 const 指针指向 非 const
    const int * p2 = &y;    // const 指针指向 const

    const int ** pp2;       // 指向指针的指针，const 不可以改指向对象的内容，但可以改指向

    // 指针之间 const 赋值问题
    p1 = p2;      // 不安全 -- 把const指针赋给非const指针
    p2 = p1;      // 有效 -- 把非const指针赋给const指针
    /* 虽然一级指针之间，非const 可以赋给 const 的，但是到了多级以后就不一样了
     * 看 void const_high_dim_pointer_problem() 的 demo
     * */
}

// const限定符的失效和指针之间的关系
void const_high_dim_pointer_problem() {
    const int **pp2;    // const 修饰二级指针确保一级指针指向的变量内容的不变
    int *p1;
    const int n = 13;

    /* const 多级指针 指向问题 */

    /* 不能通过*pp2（存储着一级指针）修改它所指向指针的内容
     * 但是如果 二级 指向 一级非 const
     * 那么，**pp2 == *p1
     * 虽然 const 二级指针 不能修改 一级指针的内容，本意上是这个
     * 但是问题是，非 const 一级可以啊
     * 所以 const 修饰不能改内容就失效了
     * */
    pp2 = &p1;    // 允许，但是这导致const限定符失效

    // 但是这将导致p1指向n（*pp2已被修改）
    *pp2 = &n;    // 有效，两者都声明为const，

    *p1 = 10;     // 有效，但是这将改变n的值（不能修改n的值）
}


void const_higher_dim_pointer_solve() {
    /* 使用 const 确保低级指针内容不会被修改 */
    const int ***ppp = nullptr;
    const int **pp = nullptr;
    const int *p = nullptr;

    int a = 10;

    p = &a;
    pp = &p;
    ppp = &pp;
}

#endif //MAIN_CPP_指针的兼容性_H
