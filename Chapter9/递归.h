//
// Created by Momo on 2023/5/12.
//

#ifndef MAIN_CPP_递归_H
#define MAIN_CPP_递归_H
#include <cstdio>
/* 英文名: recursion */

void up_and_down(int);
long fact(int n);
long rfact(int n);
void to_binary(unsigned long n);


void up_and_down(int n) {
    /* 外层函数 n = 1，里面因为 n < 4，
     * 所以 内层调用一侧 n = 2 函数，直到 n = 4 结束
     * 当 n=4 结束之后，我们就开始从 up_and_down() 这个内部开始运行结束
     * printf("LEVEL %d: n location %p\n", n, &n); n=4
     * 然后依次递减到 1 这个最开始的函数
     * */
    printf("Level %d: n location %p\n", n, &n); // #1
    if (n < 4)
        // 注意这里是的递归的开始
        up_and_down(n + 1);
    printf("LEVEL %d: n location %p\n", n, &n); // #2
}

/* 利用循环和递归分别实现阶乘运算 */
void interact_UI() {
    int num;

    printf("Enter a value in the range 0-12 (q to quit):\n");
    while (scanf("%d", &num) == 1)
    {
        // 限制用户输入的数在 0~12 之间
        if (num < 0 || num > 13)
            printf("Keep input 0 ~ 13.\n");
        else
        {
            // 展示循环和递归实现的阶乘
            printf("loop: %d factorial = %ld\n",
                   num, fact(num));
            printf("recursion: %d factorial = %ld\n",
                   num, rfact(num));
        }
        printf("Enter a value in the range 0-12 (q to quit):\n");
    }
    printf("Bye.\n");
}

/* 使用循环的函数 */
long fact(int n) {
    long ans;

    for (ans = 1; n > 1; n--)
        ans *= n;

    return ans;
}

// 使用递归的函数处理 尾计算
long rfact(int n)
{
    long ans;

    if (n > 0)
        ans = n * rfact(n - 1);     // 递归的使用
    else    // 结束标志 n = 0 返回 1
        ans = 1;

    return ans;
}


/* 实现是十进制转换二进制数 */
void to_binary(unsigned long n) {
    int r;      // 余数
    r = (int)n % 2;
    if (n>=2)
        to_binary(n / 2);   // 实现了商不断那往下除
    putchar(r==0 ? '0' : '1');
}

#endif //MAIN_CPP_递归_H