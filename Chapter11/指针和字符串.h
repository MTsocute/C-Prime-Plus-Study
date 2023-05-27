//
// Created by Momo on 2023/5/22.
//

#ifndef MAIN_CPP_指针和字符串_H
#define MAIN_CPP_指针和字符串_H
#include <cstdio>

void p_and_s() {
    const char * ptr = "Your mama";
    const char * copy;
    copy = ptr;     // 指向了同一个地址

    printf("ptr = %s, &ptr = %p, value = %p\n", ptr, &ptr, ptr);
    printf("copy = %s, &copy = %p, value = %p\n", copy, &copy, copy);

}


#endif //MAIN_CPP_指针和字符串_H
