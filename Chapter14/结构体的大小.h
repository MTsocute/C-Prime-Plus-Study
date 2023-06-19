//
// Created by Momo on 2023/6/19.
//

#ifndef C_LEARNING_结构体的大小_H
#define C_LEARNING_结构体的大小_H

#include <cstdio>
#include <cstdlib>
#include <iostream>

// 结构体整体大小是多少呢？
struct MyStruct {
    int field1;     // 4 byte
    char field2;    // 1 byte
    double field3;  // 8 byte
};

// 阐释结构体大小问题（所有单位是字节）
// 函数用于输出结构体大小
void show_size() {
    // 虽然结构体里面所有内容字节只有 13，但是为什么结构体整体大小居然是 16？
    // 这就是因为对齐了
    // 结构体是划分出块来存储的每个块大小保证相同这就叫块的做“对齐”

    /* ------- 分割线 --------- */

    // 块的大小是根据其中所占字节最大的类型决定的，然后用块去装填对应的元素
    // 我们的 MyStruct 的每一个块就是 8，然后我们存储对应的元素，最多需要两个块（16）
    /* 问题：填充空隙 -- > 洞
        * 我们知道每一块的大小是 8，但是 field1 + field2 只有 5，这个块填充有盈余
        * 但是如果拿来装 field3 又不够，field3 肯定得是单独的一块，所以必须是两块
        * 可是结构体要求块的对齐，那么第一块不够咋办呢？
     * */
    /* 对齐填充：
        * 为了满足对齐要求，编译器可能会在结构体的成员之间插入填充字节（洞）
        * 这些填充字节通常是未命名的位字段（无名位字段），其宽度为0或根据对齐规则确定
        * 所以第一块最后填充了三个未命名的 *位字段*，使得两个块对齐
        * 才使得我们的结构体整体大小是 16，而不是 13
     * */
    std::cout << "Size of MyStruct: "
              << sizeof(MyStruct)
              << " bytes" << std::endl;
}

#endif //C_LEARNING_结构体的大小_H
