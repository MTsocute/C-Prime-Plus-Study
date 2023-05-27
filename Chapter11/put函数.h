//
// Created by Momo on 2023/5/21.
//

#ifndef MAIN_CPP_PUT函数_H
#define MAIN_CPP_PUT函数_H
#include <cstdio>

#define MSG "I am a symbolic string constant."
#define MAXLENGTH 81

void use_of_puts_function()
{
    char words[MAXLENGTH] = "I am a string in an array.";
    const char * pt1 = "Something is pointing at me.";

    // 输入字符串打印
    puts("Here are some strings:");

    // 直接放入字符串打印
    puts(MSG);

    // 字符串数组打印
    puts(words);

    // 字符串指针打印
    puts(pt1);

    // 字符串数组打印
    words[8] = 'p';
    puts(words);
}

#endif //MAIN_CPP_PUT函数_H
