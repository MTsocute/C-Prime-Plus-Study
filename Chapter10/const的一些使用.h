//
// Created by Momo on 2023/5/19.
//

#ifndef MAIN_CPP_CONST的一些使用_H
#define MAIN_CPP_CONST的一些使用_H
#include <cstdio>

int arr[4] = {1,2,3,4};
int arr_2[4] = {1,2,3,4};
const int arr_3[4] = {1,2,3,4};

// 无法用该指针修改指向地址的内容，但是用其他指针修改
void mod() {
    const int * p = arr;    // 固定指针指向数组首地址
    arr[0] = 12;
    printf("arr[0] = %d\n", arr[0]);
}

// 指针本身是可以指向别处的哦
void mod_pointer() {
    const int * p = arr;    /* 创建的是一个不可以修改指向的值，但是可以改变位置的指针 */
    p++;
    printf("*p = %d\n", *p);
    p = arr_2;
    printf("*p = %d\n", *p);
}

// 非 const 指针不可以指向 const 数组
void pointer_without_const() {
    const int * p1 = arr_3;     // OK
    /*
     * 仔细想也合理
     * const 指针本身就不能修改数组的内容这个是对的
     * 但是 非 const 指针是可以的啊
     * 但是数组又是 const 修饰，数组也不能改变的啊
     * 所以干脆就别 非const 指针指向 const 数组了
     * */
//    int * p2 = arr_3;     // False
}

void locked_loc_pointer() {
    int * const p = arr;    /* 不可以修改位置，但是可以修改内容的指针 */
    *p = 100;   // 修改内容
    printf("*p = 1000\n");

    /* 修改指向就会报错 */
    p = arr;
}


#endif //MAIN_CPP_CONST的一些使用_H
