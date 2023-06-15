//
// Created by Momo on 2023/6/13.
//

#ifndef MAIN_CPP_伸缩数组的使用_H
#define MAIN_CPP_伸缩数组的使用_H
#include <cstdio>
#include <cstdlib>

/* 伸缩数组的使用 */
struct flex {
    int count;
    double average;
    // 必须得是最后一个!
    double scores[];    // 伸缩型数组成员
};

// 伸缩数组就是为了灵活可变，通过 malloc() 来动态实现自己多大多小
size_t flex_size = sizeof(struct flex);
size_t scores_size = 5 * sizeof(double);
cool = malloc(flex_size + scores_size);


#endif //MAIN_CPP_伸缩数组的使用_H
