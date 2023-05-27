//
// Created by Momo on 2023/5/21.
//

#ifndef MAIN_CPP_字符串定义_H
#define MAIN_CPP_字符串定义_H
#include <cstdio>


// 这里会解决一个我疑惑了很久的问题，为什么每次对字符串内部换行的时候就分成两个
// 我们顺便回忆一下之前的 Chapter10 的复合字面量的问题
char * str1 = (char [10]) {"你好\0"};

// "你好"：你中间换行
char * str2 = (char [10]) {"你"
                           "好\0"};

/* 打印完上面两个，你就会发现是等价的
 * 说明："""" 只要中间不断开，就是相当于一行 "" 字符串的
 * */
void showString(const char * p) {
    puts(p);
}


// 利用 "" 初始化的字符串数组，"" 对于其来说到底是什么呢，是指针吗？
void dot_sym() {
    /*
     * %p 打印了这个字符串的首地址
     * *"space farers"：相当于解引用指针
     * 指针指向首地址的元素就是 s
     * */
    printf("%s, %p, %c\n",
           "We", "are", *"space farers");
}

// 字符串初始化细节
char char_arr[10] = {
    // 一定要有 \0 作为结尾，不然就是一个数组而不是字符串
    'n', 'h','\0'
};

#endif //MAIN_CPP_字符串定义_H
