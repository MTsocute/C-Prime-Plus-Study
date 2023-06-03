//
// Created by Momo on 2023/5/30.
//

#ifndef MAIN_CPP_EXTERN声明外部变量_H
#define MAIN_CPP_EXTERN声明外部变量_H
#include "作用域.h"


/* 外部变量 */
int Errupt;
double Up[100];

// 访问外部文件的外部变量
extern long bigbig_number;  /* 引用外部文件的外部变量 */
void use_external_variable_from_external_file() {
    // 使用外部文件的外部变量
    printf("bigbignumber = %ld", bigbig_number);
}



void block_area() {
    /* Errupt 和 Up 是全局变量，在该文件作用域下
     * extern 就是访问外部的那两个变量
     * 但是 如果没有 extern 的话，内部的同名变量就是快作用域下的新建的了
     * */
    extern int Errupt;
    extern double Up[];
}



#endif //MAIN_CPP_EXTERN声明外部变量_H
