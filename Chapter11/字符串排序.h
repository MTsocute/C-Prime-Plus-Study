//
// Created by Momo on 2023/5/27.
//

#ifndef MAIN_CPP_字符串排序_H
#define MAIN_CPP_字符串排序_H
#include <cstdio>
#include <cstring>
#define SIZE 81     /* 限制字符串长度 */
#define LIM 20      /* 可读入最多行数 */
#define HALT ""     /* 空字符停止输入 */

// 字符串排序函数
void sort_str(char * strings, int len);
// 处理字符串外部输入越界问题
void s_get(char * str[], int n);
// 获取外部用户输入并赋值给字符串 n 用于限定输入字符数量
char * s_get(char * str, int n);
// 遍历字符串数组
void iter_str(char * str_arr);


// 实现主要逻辑操作的函数
void main_function() {
    char arr[LIM];

    puts("请输入 a~b 之间的 20 个字符，程序将自动实现排序: ");
    s_get(arr, LIM);
    puts("排序中....");
    sort_str(arr, strlen(arr));
    puts("输出结果：");
    iter_str(arr);
}


void iter_str(char * str_arr) {
    for (int i = 0; i < strlen(str_arr); ++i) {
        printf("%c ", str_arr[i]);
    }
    printf("\n");
}

// 冒泡排序
void sort_str(char arr[], int len) {
    for (int i = 0; i < len-1; ++i)
        for (int j = 0; j < len -i - 1; ++j)
            // 注意比较的字符串而不是单独的字符
            // 我们取地址，就是从这个位置后面开始的字符串比较
            if(arr[j] > arr[j+1])
            {
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}


char * s_get(char * str, int n) {
    // 获取外部用户输入
    char * real_val;
    real_val = fgets(str, n, stdin);

    // 处理 \n 和 \0
    if(real_val) {
        char * find = strchr(real_val, '\n');
        if (find)
            *find = '\0';
        else { while ((getchar()) != '\n') continue; }
    }
    return real_val;
}

#endif //MAIN_CPP_字符串排序_H
