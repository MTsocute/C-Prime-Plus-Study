//
// Created by Momo on 2023/4/25.
//

#ifndef MAIN_CPP_ASCII_TIP_H
#define MAIN_CPP_ASCII_TIP_H
#include <cstdio>

void ts01() {
    printf("Hello");
}

// ASCII 对一单一字符的多种表示方式
void ASC() {
    char litter = 65;
    char litter_1 = '\101';
    char litter_2 = '\x41';

    printf("1 = %c\n", litter);
    printf("2 = %c\n", litter_1);
    printf("3 = %c\n", litter_2);
}


#endif //MAIN_CPP_ASCII_TIP_H
