//
// Created by Momo on 2023/5/19.
//

#ifndef MAIN_CPP_合理的使用对数组使用_CONST_形参_H
#define MAIN_CPP_合理的使用对数组使用_CONST_形参_H
#define SIZE 5
#include <cstdio>

void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);
void main_function()
{
    double dip[SIZE] = { 20.0, 17.66, 8.2, 15.3, 22.22 };

    printf("The original dip array:\n");
    show_array(dip, SIZE);
    mult_array(dip, SIZE, 2.5);
    printf("The dip array after calling mult_array():\n");
    show_array(dip, SIZE);

}

/* 显示数组的内容 */
void show_array(const double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%8.3f ", ar[i]);
    putchar('\n');
}

/* 把数组的每个元素都乘以相同的值 */
void mult_array(double ar[], int n, double mult)
{
    int i;

    for (i = 0; i < n; i++)
        ar[i] *= mult;
}

#endif //MAIN_CPP_合理的使用对数组使用_CONST_形参_H
