//
// Created by Momo on 2023/5/7.
//

#ifndef MAIN_CPP_CHAPTER_7_H
#define MAIN_CPP_CHAPTER_7_H
#include <cstdio>
#define STOP '#'
#define SPACE ' '

void cp_7_1() {
    int space_num = 0;
    int char_num = 0;
    int next_line_sym_num = 0;
    char ch;

    while ((ch = getchar()) !=  STOP) {
        char_num ++;

        if (ch == '\n')
            next_line_sym_num ++;

        if (ch == SPACE)
            space_num ++;
    }
    printf("The number of \n");
    printf("SPACE    CHAR   '\\n'\n");

    printf("%3d %8d  %5d",
           space_num, char_num, next_line_sym_num);
}

void cp_7_4() {
    char ch;
    int change_count = 0;

    while ((ch = getchar()) != STOP) {
        if (ch == '.') {
            putchar('!');
            change_count ++;
        }

        else if (ch == '!') {
            putchar('!');
            putchar('!');
            change_count++;
        }
        else
            putchar(ch);
    }
    printf("Change times = %d", change_count);
}

void cp_7_5() {
    char ch;
    int change_count = 0;

    while ((ch = getchar()) != STOP)
    {
        switch (ch) {
            case '.' :
                putchar('!');
                change_count ++;
                break;
            case  '!' :
                putchar('!');
                putchar('!');
                change_count ++;
                break;
            default:
                putchar(ch);
                break;
        }
    }
    printf("Change times = %d", change_count);

}

void cp_7_9() {
    int n, i, j;
    printf("请输入一个整数 n：");
    scanf("%d", &n);
    printf("小于 %d 的所有素数为：\n", n);

    for (i = 2; i < n; i++) {
        int is_prime = 1;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime = 0;   // 不是素数
                break;
            }
        }
        if (is_prime == 1) {
            printf("%d ", i);
        }
    }
}

#endif //MAIN_CPP_CHAPTER_7_H
