//
// Created by Momo on 2023/5/28.
//

#ifndef MAIN_CPP_作用域_H
#define MAIN_CPP_作用域_H
#include <cstdio>

// 用于区别，块作用域下 变量和静态变量的区别
void trystat();

// 文件作用域、外部链接
int number = 20;

long bigbig_number = 5201314;

// 文件作用域、内部链接
static int inside = 20;

// 块作用域下的静态存储变量
int more(int number)
{
    int index;
    // 块作用域下变量也可以用于静态存储周期
    static int ct = 0;  /* 在运行这个函数的时候，变量就存在了，可以返回出来用 */
    return ct;
}


// 使用 auto 区别与外部变量同名的情况
void auto_variable() {
    // 虽然说不加也是不同于外部变量的number，但是加也是用于区别
    auto int number = 100;

    printf("Number from Inside = %d\n", number);

}

void static_main_function() {
    int count;

    for (count = 1; count <= 3; count++)
    {
        printf("Here comes iteration %d:\n", count);
        trystat();
    }
}


void trystat() {
    int fade = 1;               /* 块作用域下的自动变量 */
    static int stay = 1;        /* 块作用域下的静态变量 */
    // 自动变量的自增加，不会随着迭代不不断变大，下一次的循环就结束了
    printf("fade = %d and stay = %d\n", fade++, stay++);
}


// 内层块和外层块的变量同名的情况
void sameName_but_differentArea() {

    int x = 30;             // 原始的 x
    printf("x in outer block: %d at %p\n", x, &x);


    /* 内层和外层 x 不同名 */
    {
        int x = 77;         // 新的 x，隐藏了原始的 x
        printf("x in inner block: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);

    while (x++ < 33)        // 原始的 x
    {
        int x = 100;        // 新的 x，隐藏了原始的 x
        x++;
        /* 为什么 三次打印结果都是 101，而且地址还相同
         * 到了内部块 x 运行，平替了外层块的 x
         * 然后这个块结束，内部块的 x 就消失
         * */
        printf("x in while loop: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);
}


void for_outside(void) {
    puts("Hello world");
}


// 寄存器变量
void register_variable() {
    // 声明一个寄存器变量
    register int number;    /* 访问更快，但是也是块作用域 */
}


#endif //MAIN_CPP_作用域_H