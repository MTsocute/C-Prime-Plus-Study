//
// Created by Momo on 2023/6/12.
//

#ifndef MAIN_CPP_结构体_H
#define MAIN_CPP_结构体_H
#include <cstdio>
#include <cstdlib>
#define MAXTITL 41
#define MAXAUTL 31
#define LEN 20


// 创建一个结构体
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

// 创建一个结构体的同时创建对应的变量
struct book2 {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
} good_book;


/* 初始化一个结构体变量 */

// 全部初始化，按顺序
struct book nice {
    "babablaalala",
    "Momo",
    200000000.123123123
};

// 初始化指定部分
struct book nice2 {
        .value = 200000000.123123123
};

// 初始化全部，不按顺序
struct book nice3 {
    .author = "momo",
    .title = "Me and my friend",
    .value = 250.12
};


/* 结构体数组
 * 数组名：library
 * 数组下的每一个变量都是 struct book 类型
 * */
struct book library[10];


struct names {
    char first[LEN];
    char last[LEN];
};

// 注意结构体内部是变量所以要有变量名
struct guy {
    struct names handle;     /* 结构体嵌套结构体 */
    char favfood[LEN];
    char job[LEN];
    float income;
};


// 结构体嵌套匿名：不需要在外名声明一个结构体，里面再见一个变量了
struct person
{
    int id;
    // 匿名结构
    struct {char first[20]; char last[20];};
};



/* 使用结构体指针 */
void use_of_StructPoint() {
    // 结构体数组
    struct guy fellow[2] = {
            { { "Ewen", "Villard" },
                    "grilled salmon",
                    "personality coach",
                    68112.00
            },
            { { "Rodney", "Swillbelly" },
                    "tripe",
                    "tabloid editor",
                    432400.00
            }
    };
    struct guy * him;        /* 这是一个指向结构的指针 */

    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    // 注意结构体不是数组，变量名存储的不是指向地址的指针，还是需要取地址
    him = &fellow[0];        /* 告诉编译器该指针指向何处  */

    printf("pointer #1: %p #2: %p\n", him, him + 1);

    /* 使用指针访问成员的值 */
    printf("him->income is $%.2f: (*him).income is $%.2f\n",
           him->income, (*him).income);
    him++;                   /* 指向下一个结构      */
    printf("him->favfood is %s:  him->handle.last is %s\n",
           him->favfood, him->handle.last);
}


#endif //MAIN_CPP_结构体_H
