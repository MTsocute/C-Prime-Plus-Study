//
// Created by Momo on 2023/4/26.
//

#ifndef MAIN_CPP_SCANF返回值_H
#define MAIN_CPP_SCANF返回值_H
#include <cstdio>

// 我们没有正常的输入一个正确的类型，scanf() 返回 0
void wrong_format() {
    int a, feed_back_num_scanf;
    printf("请输入一个数值：");                 // 我们在里面输入 a123
    feed_back_num_scanf = scanf("%d", &a);   // scanf() 成功赋值几个，就会返回几个
    printf("%d\n", feed_back_num_scanf);
}


#endif //MAIN_CPP_SCANF返回值_H
