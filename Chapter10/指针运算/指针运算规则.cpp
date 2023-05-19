//
// Created by Momo on 2023/5/19.
//

#include "指针运算规则.h"

/* 创建可用的数据 */
int data[2] = { 100, 200 };
int moredata[2] = { 300, 400 };
int urn[5] = { 100, 200, 300, 400, 500 };


// 测试使用的
void hello(){
    printf("hello world\n");
}

// 指针运算优先级
void pointer_op_order() {
    int *p1, *p2, *p3;

    p1 = p2 = data;
    p3 = moredata;

    // 告诉原来指针对应的元素
    printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n", *p1, *p2, *p3);
    /* 由于 * ++ 优先级相同，所以运算规律是从右到左
     * *p1++：由于是后 ++ 操作，所以是先赋值后 ++，
        * 就导致了，指针所在的当前位置先赋值出来
        * 然后在位移到 200 的位置上
     * *++p：是先对指针 ++ 操作，所以是先位移后赋值，就直接是 200
     * (*p)++：先解引用，所以导致先赋值，然后拿到了数，相当于对数 ++ 而不是指针本身
     */
    printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
    printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n", *p1, *p2, *p3);
}

// 了解指针基本信息
void pointer_info() {
    int * ptr1;
    ptr1 = urn;            // 把一个地址赋给指针

    // ptr1 = <指针的值>, *ptr1 = <指针指向的值>, &ptr1 = <指针本身的地址>
    printf("pointer value, dereferenced pointer, pointer address:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
}

// 指针的加法
void pointer_add() {
    int * ptr1, *ptr2, *ptr3;

    ptr1 = urn;            // 把一个地址赋给指针
    ptr2 = &urn[2];        // 把一个地址赋给指针

    // 指针加法
    ptr3 = ptr1 + 1;
    printf("\nadding an int to a pointer:\n");
    /* 会给出第二个数组元素的地址，然后再给出第一个数组元素的地址
     * 指针内部存储的是数组的地址
     * 对指针 + 1，会导致存储的数组地址按对应字节偏移，这里是 4 个字节
     * 由于地址存储是 16 进制，所以我们转换要
     * (首 - 尾)H --> 10进制(B)
     * */
    printf("ptr1 + 1 = %p, *(ptr1 + 1) = %d, &ptr1 = %p\n",
           ptr3, *(ptr3), ptr1);
}

// 指针 ++ -- 操作
void pointer_plus_deduce() {
    int * ptr1, *ptr2, *ptr3;

    ptr1 = urn;            // 把一个地址赋给指针
    ptr2 = &urn[2];        // 把一个地址赋给指针

    ptr1++;                // 递增指针
    printf("\nvalues after ptr1++:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

    ptr2--;                // 递减指针
    printf("\nvalues after --ptr2:\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);

    --ptr1;                // 恢复为初始值
    ++ptr2;                // 恢复为初始值

    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
}

// 指针减法
void pointer_deduce() {
    int * ptr1, *ptr2, *ptr3;

    ptr1 = urn;            // 把一个地址赋给指针
    ptr2 = &urn[2];        // 把一个地址赋给指针

    // 指针加法
    ptr3 = ptr1 + 4;

    // 一个指针减去另一个指针
    /* 得到的结果是 2
     * 但是这里的 2 代表的意思是中间相差了 2 个 int
     * 而不是相差 2 个字节
     * */
    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n", ptr2, ptr1, ptr2 - ptr1);

    // 一个指针减去一个整数
    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);
}