//
// Created by Momo on 2023/5/5.
//

#ifndef MAIN_CPP_GET_PUT_CHAR_H
#define MAIN_CPP_GET_PUT_CHAR_H
#include <cstdio>
#include <cctype>       // 包含 isalpha() 函数
#define SPACE ' '
void display(char cr, int lines, int width);

/* 所有非空格字母后退一个 */

void cypher() {
    char ch;
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch))        // 这个函数会判别是否是字符串
            putchar(ch + 1);
        else
            putchar(ch);
    }
}


// putchar() 不会跳过占位符号，所以会带来一些意想不到的问题
void putchar_problem() {

    int ch;                /* 待打印字符 */
    int rows, cols;        /* 行数和列数 */
    printf("Enter a character and two integers:\n");

    // 没等我们输入新的一行，就直接说 Bye了
    /* 假设我们的输入是 c 2 3
     * 但其实是 c 2 3 '\n'
     * gethcar() 不会忽略 '\n'
     * 所以对应 c 2 3 赋值结束以后，就把 '\n' 赋给了 ch
     * 然后 ch != '\n'，就 false 了 所以循环直接结束
     * */
    while ((ch = getchar()) != '\n')
    {
        scanf("%d %d", &rows, &cols);
        display(char(ch), rows, cols);
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");
}


void correct_edition() {
    int ch;                /* 待打印字符 */
    int rows, cols;        /* 行数和列数 */
    printf("Enter a character and two integers:\n");

    while ((ch = getchar()) != '\n')
    {
        scanf("%d %d", &rows, &cols);
        display(char(ch), rows, cols);

        // 多余的部分，防止下一次新输入的时候，误赋
        while (getchar() == '\n')
            continue;

        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");
}



void display(char cr, int lines, int width)
{
    int row, col;

    for (row = 1; row <= lines; row++)
    {
        for (col = 1; col <= width; col++)
            putchar(cr);
        putchar('\n');    /* 结束一行并开始新的一行 */
    }
}


void cp_ts() {
    char ch;
    while ((ch = getchar()) != '\n') {
        putchar(ch++);
        putchar(++ch);
        putchar('\n');
    }
}

#endif //MAIN_CPP_GET_PUT_CHAR_H
