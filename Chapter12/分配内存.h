//
// Created by Momo on 2023/5/31.
//

#ifndef MAIN_CPP_分配内存_H
#define MAIN_CPP_分配内存_H
#include <cstdio>
#include <cstdlib>
#include <cstring>


void use_of_malloc() {
    double *p;
    int n = 10;
    // 数组本来是不可以用变量决定大小的
    // eg. double arr[n]; NOT ALLOWED
    p = (double *) malloc(n * sizeof (double) );
    free(p);
}

void use_of_calloc() {
    long *ptr;
    ptr = (long *) calloc(32, sizeof (long ));
    free(ptr);
}

// 创建高纬度数组
void high_dim_malloc() {
    int n = 5;
    int m = 6;
    /* 多位数组指针 */
    int (*p2)[6];

    // 创建二维数组
    p2 = (int (*)[6]) malloc(n * 6 * sizeof(int));
    free(p2);
}

void use_MallocAndFree() {
    double *ptd;
    int max;
    int number;
    int i = 0;

    printf("输入一个值，设置这个数组最大的长度: ");
    if (scanf("%d", &max) != 1) {
        puts("你输的不是数字啊？ -- bye.");
        exit(EXIT_FAILURE);     /* 表示异常程序中断 */
    }
    ptd = (double *) malloc(max * sizeof(double));
    if (ptd == nullptr) {
        puts("内存分配失败。-- Goodbye.");
        exit(EXIT_FAILURE);
    }

    /* ptd 现在指向有max个元素的数组 */
    puts("输入一个值 (q to quit):");
    // 输入一个值，赋到数组中
    while (i < max && scanf("%lf", &ptd[i]) == 1) { ++i; }

    printf("您一共输入了 %d 次数据\n", number = i);
    for (i = 0; i < number; i++) {
        printf("%7.2f ", ptd[i]);
        if (i % 7 == 6)     // 让打印美观一些
            putchar('\n');
    }

    // 不满一行 7 个，换行
    if (i % 7 != 0)
        putchar('\n');
    puts("Done.");

    free(ptd);
}

/* 静态变量 */
int static_store = 30;
const char *pcg = "String Literal";

void whereIstheMemory() {

    /* 自动存储变量 */
    int auto_store = 40;
    char auto_string [] = "Auto char Array";

    int * pi;
    char * pcl;

    /* 输出结果：
     * static_store: 30 at 0x102774000
     * auto_store: 40 at 0x16d69349c
     * *pi: 35 at 0x600001f04030
     * String Literal at 0x10276ff11
     * Auto char Array at 0x16d6934a0
     * Dynamic String at 0x600001f04040
     * Quoted String at 0x10276ffaa
     */

    /* 动态分配内存 */
    pi = (int *) malloc(sizeof(int));
    *pi = 35;
    pcl = (char *) malloc(strlen("Dynamic String") + 1);
    strcpy(pcl, "Dynamic String");

    printf("static_store: %d at %p\n", static_store, &static_store);
    printf("  auto_store: %d at %p\n", auto_store, &auto_store);
    printf("        *pi: %d at %p\n", *pi, pi);
    printf("  %s at %p\n", pcg, pcg);
    printf(" %s at %p\n", auto_string, auto_string);
    printf("  %s at %p\n", pcl, pcl);

    /* 字符串字面量，就是一个静态地址 */
    printf("   %s at %p\n", "Quoted String", "Quoted String");

    free(pi);
    free(pcl);
}

#endif //MAIN_CPP_分配内存_H