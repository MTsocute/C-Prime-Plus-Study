//
// Created by Momo on 2023/5/22.
//

#ifndef MAIN_CPP_字符串输入输出函数_H
#define MAIN_CPP_字符串输入输出函数_H

#define STLEN 14
#define STLEN_2 10
#include <cstdio>
#include <cstring>

/* fputs and fgets 的使用 */
void use_of_fgets_fputs() {
    char words[STLEN];
    puts("Enter a string, please.");

    /* 关于 fgets() 的参数：
        * 1.写入的对象
        * 2.限制的长度
        * 3.从键盘输入数据
     * */
    fgets(words, STLEN, stdin);

    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);    // 会自动在末尾添加换行符号
    /* fputs() 的参数：
        * 1.读出的对象
        * 2.读出到屏幕
     * */
    fputs(words, stdout);   // 不会在末尾添加换行符号的
}


// fgets() 使用正确会返回一个指针
// 读到文件结束以后会返回一个空指针(nullptr 指向一个安全的空白地址)
void fgets_detail() {
    char words[STLEN_2];

    puts("Enter strings (empty line to quit):");
    // 你可以试下如果输入的内容超过数组限定长度会怎么样
    // 数组末尾就是 nullptr == '\0'
    while (fgets(words, STLEN_2, stdin) != nullptr && words[0] != '\n')
        fputs(words, stdout);   // 不会自动换行的
        // puts(words); // 这个看分段的效果会好很多
    puts("Done.");
}

/* scanf() 溢出问题*/
void scanf_problem() {
    char name1[11], name2[11];
    int count;

    printf("Please enter 2 names.\n");
    // 这里，我们可以使用字段宽度限制溢出，但是如果两个字符串连在一起溢出是另外一回事
    /* 结合书本 P824
     * 如果我们输入 OK hduishiauhsdiuashdi(这个会被限制长度)
     * 但是如果我如果我们输入：nimade shabi
     * name1 = nima ; name2 = deshabi
     * name1 的溢出会到 name2 去
     * */
    count = scanf("%5s %10s", name1, name2);
    printf("I read the %d names %s and %s.\n", count, name1, name2);
}

// 该程序读取输入行，删除储存在字符串中的换行符，如果没有换行符，则丢弃数组装不下的字符
void skip_func() {
    char words[STLEN];
    int i;

    printf("Enter strings (empty line to quit): ");
    // 直到用户输入为一个换行之前一直循环
    while (fgets(words, STLEN_2, stdin) != nullptr && words[0] != '\n')
    {
        i = 0;
        // 要么句中停下来，要么句子过长停下来
        while (words[i] != '\n' && words[i] != '\0')
            i++;    // 这个时候停止的位置就是\n 或 null 也决定了越界与否
        if (words[i] == '\n')   // 说明没有越界
            words[i] = '\0';
        else    // 这里是：word[i] == '\0'的情况，说明是越界了的
            while (getchar() != '\n')   // 越界的部分只会留下一个换行符
                continue;
        /*
         * 使用 while (getchar() != '\n') continue;
         * 来循环读取并丢弃输入缓冲区中的字符
         * 确保在下一次循环中能够正确获取用户的输入。
         * 它会消耗掉多余的字符，以免影响程序的逻辑和后续的输入操作
         * */
        puts(words);
    }
    puts("done");
}

#endif //MAIN_CPP_字符串输入输出函数_H
