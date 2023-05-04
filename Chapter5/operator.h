//
// Created by Momo on 2023/4/28.
//

#ifndef MAIN_CPP_WHEAT_H
#define MAIN_CPP_WHEAT_H

#include <cstdio>
#define SQUARES 64  // 棋盘中的方格个数

/* 指数增长 */
void exp_func() {
    const double CROP = 2E16;   // 全世界小麦年产量
    double current , total;

    int count = 1;  // while 循环终止条件

    // 展示：
    printf("square     grains added       total grains     fraction of the world\n");
    total = current = 1.0;        /* 从1颗谷粒开始 */
    printf("%3d \t%13.2e \t\t%12.2e \t\t%13.2e\n",
           count, current, total, total / CROP);

    // 利用 while 指数增长到 64
    while (count < SQUARES) {
        count += 1;
        current = 2 * current;      /* 随着格子个数增加，数量开始翻倍 */
        total = total + current;    /* 更新总数量 */

    printf("%3d \t%13.2e \t\t%12.2e \t\t%13.2e\n",
           count, current, total, total / CROP);
    }
}

/* 运算优先级 */
void who_come_first() {
    float number;
    // 我们知道，乘除的优先级 >  + -，但是按照计算机 = 从右边往左边赋值的逻辑下
    number = 25.0 + 60.0 * 6.0 / 2.0;   //  "*"、"/" 谁先算呢？
    printf("%12.2f\n", number);     // 从答案中，我们可以推断出，如果优先级相同，就是从左往右运算了
}

/* 复杂一些的优先级 */
void who_come_first_2() {
    int top, score;
    // 哪个 (()) 怎么算呢？
    top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3)); /* 子括号(2+3) 先行运算 */
    printf("top = %d, score = %d\n", top, score);
}

/* 取模运算符：把 秒 转换成 分和秒 */
void time_func() {
    int sec, min, left;
    const int SEC_PER_MIN = 60;

    printf("Convert seconds to minutes and seconds!\n");
    printf("Enter the number of seconds (<=0 to quit):\n");
    scanf("%d", &sec);  // 读取秒数
    while (sec > 0)
    {
        min = sec / SEC_PER_MIN;     // 截断分钟数
        left = sec % SEC_PER_MIN;    // 剩下的秒数

        printf("%d seconds is %d minutes, %d seconds.\n", sec, min, left);
        printf("Enter next value (<=0 to quit):\n");
        scanf("%d", &sec);
    }
    printf("Done!\n");
}

/* 负数的取模运算 */
void min_cal() {
    // 看作正数的正常运算，可只有第一个数会决定结果的正负
    printf("%+d / %+d = %+d\n", 11, 5, 11 % 5);
    printf("%+d / %+d = %+d\n", 11, -5, 11 % -5);
    printf("%+d / %+d = %+d\n", -11, 5, -11 % 5);
    printf("%+d / %+d = %+d\n", -11, -5, -11 % -5);
}

/* ++ 运算符 */
void pre_plus_op() {
    int a = 1, b = 1;
    int a_post, pre_b;

    // 在这里你会发现 前++和后++的区别
    a_post = a++;   // 使用之后，再递增
    pre_b = ++b;    // 先递增，后使用

    printf("a  a_post   b   pre_b \n");
    printf("%1d %5d %5d %5d\n", a, a_post, b, pre_b);
}


/* ++ 运算要考虑的东西 */
void post_plus_op() {
    int pre_op = 0 , op_post = 0;
    while (++pre_op < 5) {
        printf("%d ", pre_op);
    }
    printf("pre_last = %d\n", pre_op);

    printf("--------------------\n");

    while (op_post++ < 5) {
        printf("%d ", op_post);
    }
    printf("post_last = %d", op_post);
}

/* 没有 {} 的运行规则 */
void without_brace() {
    int a = 0;
    while (++a < 5)     // 如果 while 没有 {} 就会以第一个 ; 为里面的内容
        printf("a = %d", a);
    printf("Done!");
}

void without_brace_demo2() {
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
            printf("%3d", 10*i+j);
}

// 一个要知道的运算方法
void other_op() {
    x *= 3 * y + 12;  // 等价于：x = x * (3 * y + 12)
}

#endif