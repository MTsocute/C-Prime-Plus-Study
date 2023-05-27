//
// Created by Momo on 2023/5/20.
//

#ifndef MAIN_CPP_指向多维数组的指针_H
#define MAIN_CPP_指向多维数组的指针_H
#define ROWS 3
#define COLS 4
#define SLEN 40
#define LIM 5

#include <cstdio>

// 这里我们提出一个问题，一个多维数组，我们如何利用一个指针指向它呢？
// 答：
int (*p)[2];    /* 多维数组指针：用于指向一个含有两个 int 多维数组的指针 */
int * p_arr[2]; /* 指针数组：含有两个 int 指针的数组 */

// 使用数组指针案例
void multi_dim_pointer() {
    int zippo[4][2] = {
        { 2, 4 },
        { 6, 8 },
        { 1, 3 },
        { 5, 7 }
    };

    int (*pz)[2];   // 多维数组指针：指向含有两个 int 数组的数组的指针
    pz = zippo;     // 指向多维数组

    // 用法和多维数组指针一模一样，就直接把 pz 看作为二级指针就可以了
    printf("   pz = %p,    pz + 1 = %p\n",    pz, pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n",    pz[0], pz[0] + 1);
    printf("  *pz = %p,   *pz + 1 = %p\n\n",    *pz, *pz + 1);

    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("  *pz[0] = %d\n", *pz[0]);
    printf("    **pz = %d\n\n", **pz);

    printf("      pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));
}

/* 既然有了指向多维数组的指针，那么我们就又了接受多维数组的形参 */
// 1. 方法一
void somefunc_1(int (*p)[3]);
// 2. 方法二
void somefunc_2(int arr[][3]);  // 最左边的[] 可以省略，表示 arr[] 是一个指针



// 多种方法接受多维数组
void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int);       // 省略形参名，没问题
int sum2d(int(*ar)[COLS], int rows);    // 数组指针接受



/* 数组指针和字符串数组 */
void pointer_arr_and_string_arr() {
    /* 他们有个很大的差别
     * 前面也在一直强调，就是静态和动态
     * 数组所在的位置一定是动态的，本质是把字面量复制到数组中去
     * 指针则是静态的指向字面量所在的静态地址
     * 所以指针必须要用 const，内容不可以修改
     * 但是数组可以，它不会修改原来的静态字面量，而是一个复制来的字面量
        * 所以指针占用的内存其实还比较少
        * 但是需要修改的时候，还是得用数组
     * */
    // 指针数组
    const char *mytalents[LIM] = {
            "Adding numbers swiftly",
            "Multiplying accurately",
            "Stashing data",
            "Following instructions to the letter",
            "Understanding the C language"
    };
    // 字符串数组
    char yourtalents[LIM][SLEN] = {
            "Walking in a straight line",
            "Sleeping",
            "Watching television",
            "Mailing letters",
            "Reading email"
    };

    int i;

    puts("Let's compare talents.");
    printf("%-36s  %-25s\n", "My Talents", "Your Talents");

    // 显示两个数组的内容
    for (i = 0; i < LIM; i++)
        printf("%-36s  %-25s\n", mytalents[i], yourtalents[i]);
    printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n",
           sizeof(mytalents), sizeof(yourtalents));
}

// 入口函数
void main_usage() {
    int junk[ROWS][COLS] = {
        { 2, 4, 6, 8 },
        { 3, 5, 7, 9 },
        { 12, 10, 8, 6}
    };

    sum_rows(junk, ROWS);
    sum_cols(junk, ROWS);
    printf("Sum of all elements = %d\n", sum2d(junk, ROWS));
}

/* 遍历计算一行之和 */
void sum_rows(int ar[][COLS], int rows) {
    int r;
    int c;
    int tot;

    for (r = 0; r < rows; r++)
    {
        tot = 0;
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];
        printf("row %d: sum = %d\n", r, tot);
    }
}

/* 遍历计算一列之和 */
void sum_cols(int ar[][COLS], int rows) {
    int r;
    int c;
    int tot;

    for (c = 0; c < COLS; c++)
    {
        tot = 0;
        for (r = 0; r < rows; r++)
            tot += ar[r][c];
        printf("col %d: sum = %d\n", c, tot);
    }
}

/* 所有元素之和 */
int sum2d(int ar[][COLS], int rows) {
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];

    return tot;
}

#endif //MAIN_CPP_指向多维数组的指针_H
