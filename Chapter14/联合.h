//
// Created by Momo on 2023/6/15.
//

#ifndef MAIN_CPP_链式结构体_H
#define MAIN_CPP_链式结构体_H
#include <cstdio>
#include <cstdlib>

// 联合的创建
union hold {
    int digital;
    double bigfl;
    char letter;
};

/* 局部变量内的联合体使用 */
void use_of_union() {
    union hold fit{};
    fit.letter = 'R';
}


union demo {
    int num;
    char arr[20];
};

// 不可以初始化多个值，只能一个（共用一个内存）
// union demo ts = {20, 'nimade'};


union demo myth = {.arr = "Life"};
// 两联合体变量在同一个内存
void show_address() {
    printf("%p, %p", &myth.num, myth.arr);
}

/* 全局范围内联合体变量声明 */
union demo ts = {.num = 10};

/* 联合体指针 */
void union_pointer() {
    union demo * pu = &ts;
    printf("pu->num = %d", pu->num);
}



#endif //MAIN_CPP_链式结构体_H
