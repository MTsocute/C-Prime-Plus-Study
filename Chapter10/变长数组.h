//
// Created by Momo on 2023/5/20.
//

#ifndef MAIN_CPP_变长数组_H
#define MAIN_CPP_变长数组_H
#define ROWS 3
#define COLS 4
#include <cstdio>

/* 可变数组的函数声明不可以字节初始化了，还得注意变量和数组的顺序 */

/* 1、错误 demo：不可以声明的时候，初始化
    * double variable_array[rows][cols] = {{...}, ...};
 * 2、错误 demo：函数声明的时候，注意控制其行列的变量要在数组前面
    * int sum(int variable_array[cols][rows], int cols, int rows);
 * */


// 创建一个任意变化大小的位数的多维数组
void demo_1() {
    int cols = 3;
    int rows = 4;
    // 行和列都是变量，所以可变，但是由于其是自动存储变量所有有一些限制(P730)
    double variable_array[rows][cols];
}




#endif //MAIN_CPP_变长数组_H
