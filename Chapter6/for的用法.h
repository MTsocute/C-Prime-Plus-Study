//
// Created by Momo on 2023/5/2.
//

#ifndef MAIN_CPP_FOR的用法_H
#define MAIN_CPP_FOR的用法_H
#include <cstdio>

// 这个用法比较少见，第一个值不是赋值，而是printf()
void for_but_with_printf(){
    int num = 0;
    for (printf("Keep entering numbers!\n"); num != 6;)
        scanf("%d", &num);
    printf("That's the one I want!\n");
}

// 逗号运算符
void comma_op() {
    const int FIRST_OZ = 46;   // 2013邮资
    const int NEXT_OZ = 20;    // 2013邮资
    int ounces, cost;

    printf(" ounces  cost\n");
    for (
            /* 有逗号运算符的时候，运算顺序就是从左到右 */
            ounces = 1, cost = FIRST_OZ;    // 利用逗号，让赋值有两个赋值
            ounces <= 16;
            ounces++,cost += NEXT_OZ        // 利用逗号，使得更新赋值也是两个
        )
        printf("%5d   $%4.2f\n", ounces, cost / 100.0);
}

// 逗号表达式赋值一定是赋最右边的哪一个，但是如果右边执行的操作，仍然会一一执行
void comma_op_2() {
    int money = (200, 500);

    int x, y = 0, z;
    x = (y += 3, (z = ++y + 2) + 5);

    printf("x = %d\n", x);
    printf("money = %d\n", money);
}

/* 芝诺悖论 */
void zeno() {
    int t_ct;       // 项计数
    double time, power_of_2;
    int limit;

    printf("Enter the number of terms you want: ");     // 控制等比数列项数
    scanf("%d", &limit);
    for (
            time = 0, power_of_2 = 1, t_ct = 1;
            t_ct <= limit;
            t_ct++, power_of_2 *=2.0
            )
    {
        time += 1.0 / power_of_2;   // 实现 1 + 1/2 + 1/4 （每次走一半所需要的时间）
        printf("time = %f when terms = %d.\n", time, t_ct);
    }
}



#endif //MAIN_CPP_FOR的用法_H
