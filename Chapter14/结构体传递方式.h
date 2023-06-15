//
// Created by Momo on 2023/6/13.
//

#ifndef MAIN_CPP_结构体传递方式_H
#define MAIN_CPP_结构体传递方式_H
#include <cstdlib>
#include <cstdio>

double sum_func(double val1, double val2);
void change_value(struct num * p1, struct num * p2);  // 接受结构体的地址
void change_value(struct num p1, struct num p2);          // 接受结构体的变量


struct num{
    int a;
    double b;
}a, b;

/* 传递结构体成员作为参数 */
void struct_member_as_parameter() {
    a = { .a = 10, .b = 2e3 };
    b = {20,4e2};

    double sum = sum_func(a.b, b.b);
    printf("The value is %.2lf\n", sum);
}


/* 传递结构体地址作为参数 */
void struct_address_as_parameter() {
    struct num c = {30,100.0};
    struct num d = {20,200.0};

    printf("value of c->a = %d and c->b = %lf\n", c.a, c.b);
    printf("value of d->a = %d and d->b = %lf\n", d.a, d.b);

    puts("Change Value....");

    change_value(&c, &d);

    printf("value of c->a = %d and c->b = %lf\n", c.a, c.b);
    printf("value of d->a = %d and d->b = %lf\n", d.a, d.b);
}


/* 传递结构体变量作为参数 */
void struct_variable_as_parameter() {
    struct num c = {30,100.0};
    struct num d = {20,200.0};

    printf("value of c->a = %d and c->b = %lf\n", c.a, c.b);
    printf("value of d->a = %d and d->b = %lf\n", d.a, d.b);

    puts("Change Value....");

    change_value(c, d);

    printf("value of c->a = %d and c->b = %lf\n", c.a, c.b);
    printf("value of d->a = %d and d->b = %lf\n", d.a, d.b);
}




// 返回结构体成员的和
double sum_func(double val1, double val2) {
    return (val1 + val2);
}

// 使用结构体地址作为参数
void change_value(struct num * p1, struct num * p2) {
    p1->a = 300;
    p1->b = 2400.12;

    p2->a = 120;
    p2->b = 212.1242;

    puts("Done!");
}

// 使用结构体作为参数
void change_value(struct num p1, struct num p2) {
    p1.a = 300;
    p1.b = 2400.12;

    p2.a = 120;
    p2.b = 212.1242;

    puts("Done!");
}

// 最后一种情况参数相当于复一个新的值出来，而不是两个变量名都是一个地址
struct demo {
    char ts1[10];
    char ts2p[20];
};

// 就和这个同理
struct demo mem1 = {"CaoDong", "Ghost"};
struct demo mem2 = mem1;

#endif //MAIN_CPP_结构体传递方式_H
