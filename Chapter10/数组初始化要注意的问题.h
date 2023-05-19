//
// Created by Momo on 2023/5/14.
//

#ifndef MAIN_CPP_数组初始化要注意的问题_H
#define MAIN_CPP_数组初始化要注意的问题_H

/* 常见的一些错误 */
void errors_in_arr() {
    int oxen[5] = {5, 3, 2, 8};        /* 初始化没问题 */
    int yaks[5];

    yaks = oxen;                    /* 不允许把一个数组赋给另一个数组 */
    yaks[5] = oxen[5];              /* 数组下标越界，边界是 4 */
    yaks[5] = {5, 3, 2, 8};         /* 自由第一次初始化才可以这样子 */
}
#endif //MAIN_CPP_数组初始化要注意的问题_H
