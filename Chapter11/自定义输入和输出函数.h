//
// Created by Momo on 2023/5/23.
//

#ifndef MAIN_CPP_自定义输入和输出函数_H
#define MAIN_CPP_自定义输入和输出函数_H
#include <cstdio>

// 实现put1(字符串)然后把字符串输出到屏幕
void put1(const char * string)  /* 不会改变字符串 */
{
    while (*string != '\0')     // 这个这么写比较复杂，我们可以利用特性来改


        /* putchar()，不是puts() 他是要放入一个字符串才能输出出来的
         * 而puts() 放一个地址就行
         * (* ++) 同时出现，因为 ++ 优先级高
         * 而且还是右 ++ 所以先赋值再递增
         * */
        putchar(*string++);
}

// 统计一个字符串中字符的数量
int pu1_improve(const char * string) {
    /*
    * while (*string != '\0') -->  while (*string)
    * 字符串最后的位置都是 '\0'
    * 这个时候解引用返回的就是 0 实现 while 0 结束
    * 也就是读完字符串的时候
    * */
    int count = 0;
    while (*string) {
        putchar(*string++);
        count++;
    }
    return count;
}

#endif //MAIN_CPP_自定义输入和输出函数_H
