//
// Created by Momo on 2023/6/15.
//

#ifndef C_LEARNING_指针小总结_H
#define C_LEARNING_指针小总结_H


int board[8][8];      // 声明一个内含int数组的数组
int ** ptr;           // 声明一个指向指针的指针，被指向的指针指向int
int * risks[10];      // 声明一个内含10个元素的数组，每个元素都是一个指向int的指针
int (* rusks)[10];    // 声明一个指向数组的指针，该数组内含10个int类型的值
int * oof[3][4];      // 声明一个 3×4 的二维数组，每个元素都是指向int的指针
int (* uuf)[3][4];    // 声明一个指向 3×4 二维数组的指针，该数组中内含int类型值
int (* uof[3])[4];    // 声明一个内含 3个指针元素的数组，其中每一个指针指向一个含有 4 个 int 元素的数组


#endif //C_LEARNING_指针小总结_H
