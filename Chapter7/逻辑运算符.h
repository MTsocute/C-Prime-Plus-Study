//
// Created by Momo on 2023/5/5.
//

#ifndef MAIN_CPP_逻辑运算符_H
#define MAIN_CPP_逻辑运算符_H
#include <cstdio>
#include <cctype>
#define STOP '|'    // 文本结束标识

/* 关键原则：(也叫做“短路求值”)
 * &&: 的求值顺序是从左往右。一旦发现有使整个表达式为假的因素，立即停止求值
 * ||: 的求值顺序是从左往右。一旦发现有使整个表达式为真的因素，立即停止求值
 * */
void logical_op_instance() {
    bool result;

    /*instance 1*/
    int a = 5, b = 3, c = 7;
    result = (a > b && b > c); // result = 0


    /*instance 2*/
    a = 5, b = 0;
    result = b || (a/b) > 2; // 此处除以0会产生运行时错误


    printf("%d", result);
}


/* 实现读取一个文本，识别多少 字符、字、行 */
void word_count() {
    char c;                   // 读入字符
    char prev;                // 读入的前一个字符
    long n_chars = 0L;        // 字符数
    int n_lines = 0;          // 行数
    int n_words = 0;          // 单词数
    int p_lines = 0;          // 不完整的行数：如果最后一行，没有换行，就记入不完整行
    bool new_word = false;    // 是不是一个新单词，是 = True

    printf("Enter text to be analyzed (| to terminate):\n");
    prev = '\n';              // 用于识别完整的行
    while ((c = getchar()) != STOP)
    {
        n_chars++;            // 统计字符
        if (c == '\n')
             n_lines++;       // 统计行

        if (!isspace(c) && !new_word)     // 如果不是空白且不是新单词
        {
            new_word = true;   // 没遇到空格，那么当前的词就是新词
            n_words++;         // 统计单词
        }

        if (isspace(c) && new_word) // 遇到空白，且之前是新单词
            new_word = false;   // 达到单词的末尾，即要遇到新词，现在的词变成老词

        prev = c;               // 用于最后一行检测
    }

    if (prev != '\n')   // 如果最后一行，结束比标记前没有换行，就记入不完整行
        p_lines = 1;

    printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);
}

#endif //MAIN_CPP_逻辑运算符_H
