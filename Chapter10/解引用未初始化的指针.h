//
// Created by Momo on 2023/5/19.
//

#ifndef MAIN_CPP_解引用未初始化的指针_H
#define MAIN_CPP_解引用未初始化的指针_H

void big_Problem() {
    int *p;
    // 创建了一个指针，给指针本身创建了一个存储地址
    // 但是不代表说，指针指向的那个地方也创建了一个存储地址
    // 那么指针指向的那个地址是哪里是完全位置的，就导致了 5 不知道存储在哪里
    // 如果指向内核就 GG 了
    *p = 5;
}

#endif //MAIN_CPP_解引用未初始化的指针_H
