//
// Created by Momo on 2023/6/20.
//

#ifndef C_LEARNING_变参宏_H
#define C_LEARNING_变参宏_H

#include <cstdio>

// 定义一个变参宏
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
// 变参宏 + # 粘合
#define SHOWSHOW_WAY(msg_index, ...) \
printf("Message " #msg_index ": " __VA_ARGS__)

// 使用变参宏
void use_of_variable_define() {
    const char * prt = "moive!\n";
    DEBUG_PRINT("Hello" " World!\n");
    DEBUG_PRINT("Life is fucking %s", prt);
    SHOWSHOW_WAY(1, "我要做神话里奈的狗！\n");
}


#endif //C_LEARNING_变参宏_H