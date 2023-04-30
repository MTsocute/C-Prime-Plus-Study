//
// Created by Momo on 2023/4/29.
//

#ifndef MAIN_CPP_类型转换_H
#define MAIN_CPP_类型转换_H
#include <stdio.h>

void pound(int a);     // 函数声明：这样子函数在哪个位置都可以用

void enforce_convert_1() {
    char ch;
    int i;
    float fl;

    // 允许的类型转换都基本是低转高，或者自己容许的范围内
    ch = ch + 1;                                          /* 在自己的范围的内变换 */
    i = fl + 2 * ch;                                      /* 低字节转换成高字节 */
    fl = 2.0 * ch + i;                                    /* 低字节转换成高字节 */
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);

    /* 重点关注这里 */

    // 溢出：4字节 int 转换 1字节 char，
    ch = 1107;                                            /* 第15行 */
    printf("Now ch = %c\n", ch);                          /* 第16行 */
    // 浮点转换整数：小数抹去
    ch = 80.89;                                           /* 第17行 */
    printf("Now ch = %c\n", ch);                          /* 第18行 */
}


// 有符号数直接转换成 int，不同编译器对 int 转换是有符号还是无符号是不清楚的
void enforce_convert_2() {
    char c = -1;
    int i = c;
    printf("%d", i);
}


// 整数类型给浮点赋值会出问题
void enforce_convert_3() {
    int i = 0;
    float f = i;
    i = 3.14;
    printf("%d\n", i);
}

// 函数传参的强制转换
void enforce_convert_4() {
    int times = 5;
    char ch = '!';    // ASCII码是33
    float f = 6.3f;

    pound(times);     // int类型的参数

    // 这里都进行了强制转换
    pound(ch);        // 和pound((int)ch); 相同
    pound(f);         // 和pound((int)f); 相同
}

// 根据传入参数的数，来决定打印多少个 "#"
void pound (int a) {
    while (a--) {
        printf("#");
    }
    printf("\n");
}



#endif //MAIN_CPP_类型转换_H
