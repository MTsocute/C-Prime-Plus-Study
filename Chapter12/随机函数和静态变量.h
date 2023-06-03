//
// Created by Momo on 2023/5/31.
//

#ifndef MAIN_CPP_随机函数和静态变量_H
#define MAIN_CPP_随机函数和静态变量_H
#include <cstdio>
#include <cstdlib>
#include <ctime>

unsigned int rand0();

void srand1(unsigned int seed);

void random_number();

int roll(int sides) {
    return rand() % sides + 1;
}

#endif //MAIN_CPP_随机函数和静态变量_H
