//
// Created by Momo on 2023/6/15.
//

#ifndef C_LEARNING_枚举_H
#define C_LEARNING_枚举_H
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define LEN 30

// 枚举出来的单词，就是 unsigned int 类型，对应范围就是 0 ~ 5
enum spectrum {
    red,
    orange,
    yellow,
    green,
    blue,
    violet  // 紫罗兰
};


void use_of_enum()
{   int colorIndex;
    // red = 0, violet = 5
    for (colorIndex = red; colorIndex <= violet; colorIndex++)
        continue;
}

// 我们可以自己指定枚举词对应的数值大小
enum level { low = 100, medium = 1000, high = 10000 };

void show_value() {
    printf("low = %u\nmedium = %u\nhigh = %u\n", low, medium, high);
}

/* enum.c -- 使用枚举类型的值 */
char * s_gets(char * st, int n);

// const char[6][LEN] = { ... }; to alternative below
const char * colors [] = { "red", "orange", "yellow",
                           "green", "blue", "violet" };

void main_enter()
{
    char choice[LEN];       // To store user's input
    int color;              // To iter the color
    bool color_is_found = false;

    puts("Enter a color (empty line to quit):");
    while (s_gets(choice, LEN) != nullptr && choice[0] != '\0')
    {
        for (color = red; color <= violet; color++)
        {   // 查看用户输入的字符串在不在枚举中
            if (strcmp(choice, colors[color]) == 0)
            {   // 如果在就开启 switch 循环
                color_is_found = true;
                break;
            }
        }
        if (color_is_found)
            switch (color)
            {
                case red: puts("Roses are red.");
                    break;
                case orange: puts("Poppies are orange.");
                    break;
                case yellow: puts("Sunflowers are yellow.");
                    break;
                case green: puts("Grass is green.");
                    break;
                case blue: puts("Bluebells are blue.");
                    break;
                case violet: puts("Violets are violet.");
                    break;
                default:
                    break;
            }
        else
            printf("I don't know about the color %s.\n", choice);
        color_is_found = false;
        puts("Next color, please (empty line to quit):");
    }
    puts("Goodbye!");
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');     // 查找换行符
        if (find)                    // 如果地址不是 NULL，
            *find = '\0';            // 在此处[…]
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}


#endif //C_LEARNING_枚举_H
