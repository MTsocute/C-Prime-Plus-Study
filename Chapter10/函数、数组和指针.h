//
// Created by Momo on 2023/5/17.
//

#ifndef MAIN_CPP_函数_数组和指针_H
#define MAIN_CPP_函数_数组和指针_H
#define SIZE 10
#include <cstdio>

// 只有这里声明过 int arr[] 形参的函数，才可以平替 int * arr
void brace_in_claim(int arr[], int len);     // 声明了 int arr[] 作为形参

long sump(int * start, int * end);   // 收录数组的头尾地址，实现计算数组的值

void add_to(int arr[], int len, int val);
void add_to_const(const int arr[], int len, int val);   // 防止修改外部数组里面的内容


void iter_array(int arr[], int len);    // 遍历数组

// 由于数组的变量存储的是首地址，是一个地址，所以我们要用指针来接受
void receive_demo(int * arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// 提前声明过了，所以这里才可以作为接受用的形式参
void brace_in_claim(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// 使用指针形参数，进行一些操作
void arr_add_with_pointer() {
    int marbles[SIZE] = { 20, 10, 5, 39, 4,
                          16, 19, 26, 31, 20 };
    long answer;

    answer = sump(marbles, marbles + SIZE);
    printf("The total number of marbles is %ld.\n", answer);
}

long sump(int * start, int * end) {
    long total_num = 0;
    while (start < end) {
        total_num += *(start);
        start ++;
        // 更便捷的方法，total += *start++;
    }
    return total_num;
}

// 给数组中每一个值 + 一个给定的 val 值
void add_to(int arr[], int len, int val) {
    for (int i = 0; i < len; ++i) {
        arr[i] += val;
    }
}

// 防止修改外部的数组内部的参数
void add_to_const(const int arr[], int len, int val) {
    for (int i = 0; i < len; ++i) {
        arr[i] += val;  // const 保护数组：一旦修改就会报错
    }
}


void iter_array(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



#endif //MAIN_CPP_函数_数组和指针_H
