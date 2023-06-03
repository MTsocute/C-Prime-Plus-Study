//
// Created by Momo on 2023/6/2.
//

#ifndef MAIN_CPP_ANSI_C类型限定符_H
#define MAIN_CPP_ANSI_C类型限定符_H
#include <cstdio>
#include <cstdlib>




// 修饰符使用很多的时候，多余的会忽视，只会用第一个
void IgnoreRedundant() {
    const const const int a = 123;  // equals to const int a = 123;
}


// const 使用的一些补充
void addition_of_const() {
    /* const修饰: 既不可以改变指针指向，也不能改改变指针指向数值的指针 */
    double arr[10] = {1e10, 20.123, 7897.12314};
    const double * const p = arr;

    // 第三种 const 修饰方法
    float const * ptr1;     // equals to const float * prt1;
}

void multiple_access() {
    int arr[10] = {1,2,3,4,5,6,7,8,9};

    for (int i = 0; i < 10; ++i) {
        arr[i] += 10;
        arr[i] += 10;
    }


    for (int i : arr)
        printf("%d ", i);
    printf("\n");
}



#endif //MAIN_CPP_ANSI_C类型限定符_H
