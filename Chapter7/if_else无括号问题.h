//
// Created by Momo on 2023/5/5.
//

#ifndef MAIN_CPP_IF_ELSE无括号问题_H
#define MAIN_CPP_IF_ELSE无括号问题_H
#include <cstdio>

// 如果没有花括号，那么 else 和最近的哪个 if 相匹配
void without_brace() {
    int number;
    scanf("%d", &number);

    if (number > 6)
        if (number < 12)
            printf("You're close!\n");
    // 这个 else 和 内层的 if 有关系
    else
        printf("Sorry, you lose a turn!\n");
}


/* 找素数 */
void divisor() {
    unsigned long num;          // 待测试的数
    unsigned long div;          // 可能的约数
    bool isPrime;               // 素数标记，bool 创建默认为 true

    printf("Please enter an integer for analysis; ");
    printf("Enter q to quit.\n");
    while (scanf("%lu", &num) == 1)
    {
        for (div = 2, isPrime = true; (div * div) <= num; div++)
        {
            if (num % div == 0)
            {
                if ((div * div) != num)     // 找完全平方数，如果是，就只打印一个除数
                    printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
                else
                    printf("%lu is divisible by %lu.\n", num, div);
                isPrime = false;    // 有被除数，那就改变素数标记
            }
        }
        if (isPrime)
            printf("%lu is prime.\n", num);
        printf("Please enter another integer for analysis; ");
        printf("Enter q to quit.\n");
    }
    printf("Bye.\n");
}

#endif //MAIN_CPP_IF_ELSE无括号问题_H
