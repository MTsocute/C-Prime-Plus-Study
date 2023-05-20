//
// Created by Momo on 2023/5/20.
//

#ifndef MAIN_CPP_复合字面量_H
#define MAIN_CPP_复合字面量_H
#define COLS 4
#include <cstdio>

/* 实现 一/二维数组 所有元素之和 */
int sum(const int ar[], int n);
int sum2d(const int ar[][COLS], int rows);


// 普通数组的声明初始化
int arr_normal[3] = {1,2,3};

// 使用字面量来
void demo() {
    int *ptr;
    // 因为它没有变量名，所以要用东西来接受的
    ptr = (int[3]) {1, 2, 3};
}

void demo2() {
    int (*ptr)[3];
    ptr = (int[2][3]) {
            {1,2,3},
            {4,5,6}
    };
}


void main_function()
{
    int total1, total2, total3;
    int * pt1;
    int(*pt2)[COLS];

    /* 利用字面量创建两个数组 */
    pt1 = (int[2]) { 10, 20 };
    pt2 = (int[2][COLS]) {
        {1, 2, 3, -9},
        { 4, 5, 6, -8 }
    };

    total1 = sum(pt1, 2);
    total2 = sum2d(pt2, 2);
    total3 = sum((int []){ 4, 4, 4, 5, 5, 5 }, 6);

    printf("total1 = %d\n", total1);
    printf("total2 = %d\n", total2);
    printf("total3 = %d\n", total3);

}

int sum(const int ar [], int n)
{
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
        total += ar[i];

    return total;
}

int sum2d(const int ar [][COLS], int rows)
{
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];

    return tot;
}

#endif //MAIN_CPP_复合字面量_H
