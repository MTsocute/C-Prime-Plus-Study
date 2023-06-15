//
// Created by Momo on 2023/6/13.
//

#ifndef MAIN_CPP_使用结构体数组的函数_H
#define MAIN_CPP_使用结构体数组的函数_H
#include <cstdlib>
#include <cstdio>
#define FUNDLEN 50
#define N 2


struct funds {
    char      bank[FUNDLEN];
    double    bankfund;
    char      save[FUNDLEN];
    double    savefund;
};

double sum(const struct funds money [], int n);
double sum_2(const struct funds *  money, int n);

void main_function()
{
    struct funds jones[N] =
    {
        {
                "Garlic-Melon Bank",
                4032.27,
                "Lucky's Savings and Loan",
                8543.94
            },
        {
            "Honest Jack's Bank",
                3620.88,
                "Party Time Savings",
                3802.91
            }
    };

    printf("The Joneses have a total of $%.2f.\n",
           sum(jones, N));

    printf("The Joneses have a total of $%.2f.\n",
           sum_2(jones, N));
}

double sum(const struct funds money [], int n)
{
    double total;
    int i;

    for (i = 0, total = 0; i < n; i++)
        total += money[i].bankfund + money[i].savefund;

    return (total);
}

double sum_2(const struct funds *  money, int n) {
    double total;
    int i;

    for (i = 0, total = 0; i < n; i++)
        total += money[i].bankfund + money[i].savefund;

    return (total);
}


#endif //MAIN_CPP_使用结构体数组的函数_H
