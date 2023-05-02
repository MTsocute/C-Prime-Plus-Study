//
// Created by Momo on 2023/4/26.
//

#ifndef MAIN_CPP_SCANF返回值_H
#define MAIN_CPP_SCANF返回值_H
#include <cstdio>

// 我们没有正常的输入一个正确的类型，scanf() 返回 0
void scanf_return() {
    int a, feed_back_num_scanf;
    printf("请输入一个数值：");                 // 我们在里面输入 a123
    feed_back_num_scanf = scanf("%d", &a);   // scanf() 成功赋值几个，就会返回几个
    if (feed_back_num_scanf!= -1)
        { printf("你成功输入了%d个正确的值\n", feed_back_num_scanf); }
    else { printf("请检查你输入的值！");}
}


void space_search() {
    char str;
    /*
     * 第一个：输入 空格 a 会记录空格
     * 第二个：输入 空格 a 会忽略空格找字符串
     * */
    scanf("%d", &str);
    scanf(" %d" &str);
}


#endif
