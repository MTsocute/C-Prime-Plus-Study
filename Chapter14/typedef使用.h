//
// Created by Momo on 2023/6/15.
//

#ifndef C_LEARNING_TYPEDEF使用_H
#define C_LEARNING_TYPEDEF使用_H
#include <cstdio>
#include <cstdlib>
#include <cstring>

// 将 unsigned int 改名为 DATA
typedef unsigned int DATA;

void change_name() {
    DATA arr[10];
    printf("Size of unsigned int arr is %lu", sizeof arr);
}

// 把 struct complex 从命名为 CON
typedef struct complex {
    float real;
    float imagine;
} COMPLEX;


// 省略形式书写
typedef struct {
    float real;
    float img;
} COMPLEX_2;

void demo() {
    COMPLEX_2 a;

    a.real = 123.123;
    a.img = 12;

    printf("The real number of a is %.3lf\n", a.real);
    printf("The imagine number of a is %.3lf\n", a.img);
}



#endif //C_LEARNING_TYPEDEF使用_H
