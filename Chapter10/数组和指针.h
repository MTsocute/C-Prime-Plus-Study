//
// Created by Momo on 2023/5/14.
//

#ifndef MAIN_CPP_数组和指针_H
#define MAIN_CPP_数组和指针_H
#define SIZE 4
#include <cstdio>

// 1. 数组名就是数组的首地址
void arr_name_equals_to_address_of_arr() {
    int arr[] = {1,2,3};
    if (arr == &arr[0])
        printf("They are the same");
}

// 2. 指针的加减法的对应位移
void ptr_move() {
    int index;  // 移动指针用的数

    short dates[SIZE];
    short * pti;

    double bills[SIZE];
    double * ptf;


    pti = dates;    // 把数组地址赋给指针
    ptf = bills;
    printf("%10s %10s %13s\n", "pointer", "short", "double");

    // 指针位移
    for (index = 0; index < SIZE; index++)
        printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
    /* 从结果你不难发现，结果是以16进制呈现的
        * 我们移动指针以后，short 和 double 的变化是不同改的
        * short 是 2 位、double 是 8 位
        * 于是移动指针后，不难发现，地址增加的位数就是数据的大小
     * 我们不难得出:
        * 指针的位移，就是指向下一个存储单元
     * */
}

// 3. 指针本质上是存储地址的变量，那么首地址当然也可以实现同理的操作
void arr_move() {
    int arr[3] = {1,2,3}, *p;
    p = arr;

    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr+2) = %d\n", *(p+2));
}


// 数组名是一个地址常量指针(int * const arr)，所以不可以进行 ++ 移动
//void arr_pointer_difference() {
//    int arr[3] = {1,2,3};
//    // 不可以对自身移动，不然就是换数组地址了，这个对于一个静态常量是不允许的
//    arr ++;
//    ++arr;
//    arr += 1;
//    arr = arr + 1;
//    // 但是自身移动是可以的
//    arr + 3; // 这个并不改变首地址位置，而是给我们这个地址 + 3 个字节类型的那个地址的位置
//}


// 字符串地址
#define MSG "I'm special"   // 字面量的字符串在一个静态存储区
void string_address() {
    /* 结合书本 P791~792 一起看
     * 好好理解啥字面量字符串同数组字符串的地址不同的原因
     * 一个是静态的字符串地址，一个是动态数组字符串地址
     * */
    char ar[] = MSG;    // 赋给数组以后就是一个动态变量了
    const char *pt = MSG;
    printf("address of \"I'm special\": %p \n", "I'm special");

    // 只有这个地址和别的都不同(动态)
    printf("            address ar: %p\n", ar);
    printf("            address &ar[0]: %p\n", &ar[0]);

    printf("            address pt: %p\n", pt);
    printf("        address of MSG: %p\n", MSG);
}


// 字面量静态地址带来的大问题
void static_address_issue() {
    // 静态字面里会应用到所有的字面量，全部都是一个地址
    char * p = "Nihao";     /* 指针指向静态的字面量，修改会造成大问题 */
    p[0] = 'F';     // 一修改全部都炸
    /* 所以最好还是赋给一个数组 */
    // 这里会爆炸
    printf("Nihao");
    printf("Beware of %s!\n", "Nihao");
}

#endif //MAIN_CPP_数组和指针_H
