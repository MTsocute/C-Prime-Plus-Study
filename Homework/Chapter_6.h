//
// Created by Momo on 2023/5/4.
//

#ifndef MAIN_CPP_CHAPTER_6_H
#define MAIN_CPP_CHAPTER_6_H
#include <cstdio>
#include <string.h>

/* 复习题 */
void Review_7_a() {
    int i = 0;

    while (++i < 4)
        printf("Hi\n");
    do {
        printf("Bye ");
        } while (i++ < 8);
}

void Review_7_b() {
    for (int i = 0, ch = 'A'; i < 4; ++i, ch += 2 * i) {
        printf("%c\n", ch);
    }
}

void Review_8_a() {
    char ch;
    scanf("%c", &ch);
    while (ch!='g') {
        printf("%c", ch);
        scanf("%c", &ch);   // 为什么这个 while 不会是死循环，因为 scanf() 会读取 ch 下一个部分
    }
}

void Review_8_b() {
    char ch;
    scanf("%c", &ch);
    while (ch!='g') {
        printf("%c", ++ch);     // 并不会跳跃到下一个位置去读，而是把每一个字符串都递进了一个位置
        scanf("%c", &ch);
    }
}

void Review_8_c() {
    char ch;
    scanf("%c", &ch);
    do {
        printf("%c", ch);     // 并不会跳跃到下一个位置去读，而是把每一个字符串都递进了一个位置
        scanf("%c", &ch);
    } while (ch!='g');
}



/* 编程题 */
void cp_6_1() {
    char alphabet_list[27];
    int i;
    char ch;
    for (i = 0, ch = 'a'; i < 26; ++i, ch++)
        alphabet_list[i] = ch;
    alphabet_list[i] = '\0';

    for (char u : alphabet_list) {
        printf("%c ", u);
    }
}


void cp_6_3() {
    for (char ch = 'F'; ch >= 'A'; --ch) {
        for (char ch_2 = 'F'; ch_2 >= ch; --ch_2) {
            printf("%c ", ch_2);
        }
        printf("\n");
    }
}


char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


void cp_6_3_2() {
    int j, time;
    for (int i = 0; i <= 6; i++) {
        j = 0;
        for (j += i, time = 0; time <= i; ++j, time++)
             printf("%c", lets[j]);
        printf("\n");
    }
}


void cp_6_4() {
    int j;
    for (int i = 0; i <= 4; i++) {
        for (j = 0; j < i; ++j) {
            printf("%c ", lets[j]);
        }
        for (j; j >= 0; --j) {
            printf("%c ", lets[j]);
        }
        printf("\n");
    }
}


void cp_6_7() {
    char str[30];
    printf("input a word plz:");
    scanf("%s", str);
    for (int i = (int)strlen(str); i >= 0; --i) {
        printf("%c", str[i]);
    }
    printf("\n");
}


#endif //MAIN_CPP_CHAPTER_6_H
