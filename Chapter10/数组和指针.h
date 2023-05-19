//
// Created by Momo on 2023/5/14.
//

#ifndef MAIN_CPP_数组和指针_H
#define MAIN_CPP_数组和指针_H
#define SIZE 4
#include <cstdio>

// 1. 数组名就是数组的首地址
void arr_name_equals_to_address_of_arr() {
    int arr[] = {1,2,3};
    if (arr == &arr[0])
        printf("They are the same");
}

// 2. 指针的加减法的对应位移
void ptr_move() {
    int index;  // 移动指针用的数

    short dates[SIZE];
    short * pti;

    double bills[SIZE];
    double * ptf;


    pti = dates;    // 把数组地址赋给指针
    ptf = bills;
    printf("%10s %10s %13s\n", "pointer", "short", "double");

    // 指针位移
    for (index = 0; index < SIZE; index++)
        printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
    /* 从结果你不难发现，结果是以16进制呈现的
        * 我们移动指针以后，short 和 double 的变化是不同改的
        * short 是 2 位、double 是 8 位
        * 于是移动指针后，不难发现，地址增加的位数就是数据的大小
     * 我们不难得出:
        * 指针的位移，就是指向下一个存储单元
     * */
}

// 3. 指针本质上是存储地址的变量，那么首地址当然也可以实现同理的操作
void arr_move() {
    int arr[3] = {1,2,3}, *p;
    p = arr;

    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr+2) = %d\n", *(p+2));
}

#endif //MAIN_CPP_数组和指针_H
