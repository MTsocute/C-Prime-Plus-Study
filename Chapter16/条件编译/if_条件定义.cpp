//
// Created by Momo on 2023/6/21.
//

#define HORSE 1
#define COW 0

#define ANIMAL HORSE

// 通过宏定义的值决定 引入那个头文件，提高了程序肚饿可以移植性
#if ANIMAL == HORSE

#include "horse.h"
#include <cstdio>
#include <cstring>

void mama_say() {
    puts("Life is Fucking Moive!");
}
#elif ANIMAL == COW
    #include "cow.h"
#endif