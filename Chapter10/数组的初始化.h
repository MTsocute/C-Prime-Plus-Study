//
// Created by Momo on 2023/5/14.
//

#ifndef MAIN_CPP_数组_H
#define MAIN_CPP_数组_H
#define SIZE 4
#include <cstdio>

void iterate_array(int arr[], int length);  // 用于遍历数组的函数

// 初始化小知识
void ini_arr() {
    // 如果一个数组初始化，其中不留任何数据，那么都会是随机的垃圾数据
    int arr_1[SIZE];

    // 如果填了没有填满，剩余的数据都会是 0
    int arr_2[SIZE] = {1,2};

    // {} 默认里面都是 0
    int arr_3[SIZE] = {};

    printf("Arr 1: ");
    iterate_array(arr_1, SIZE);
    printf("Arr 2: ");
    iterate_array(arr_2, SIZE);
    printf("Arr 3: ");
    // 获取数组大小的其他方法
    int len_arr_3 = sizeof arr_3 / sizeof arr_3[0];
    iterate_array(arr_3, len_arr_3);
}

// 指定位置初始化
void ini_arr_with_position() {
    int arr[12] = {12,[3] = 12 };
    int len = sizeof arr / sizeof arr[0];
    iterate_array(arr, len);

    // 如果没有指定数组的大小，那么注意下面这操作
    // 多余的数，就是从 6 以后增加
    int arr_2[] = {1, [6] = 7,8,9}; // 这个是没有错的
}

// 数组的遍历
void iterate_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


#endif //MAIN_CPP_数组_H
