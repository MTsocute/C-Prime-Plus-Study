//
// Created by Momo on 2023/6/10.
//

#ifndef MAIN_CPP_二进制IO_H
#define MAIN_CPP_二进制IO_H
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define BUFSIZE 4096
#define SLEN 81


/* append.c -- 把文件附加到另一个文件末尾 */
void append(FILE *source, FILE *dest);
char * s_gets(char * st, int n);

void main_function()
{
    FILE *fa, *fs;          // fa 指向目标文件，fs 指向源文件
    int files = 0;          // 附加的文件数量
    char file_app[SLEN];    // 目标文件名
    char file_src[SLEN];    // 源文件名
    int ch;

    /* 找目标文件 */
    puts("Enter name of destination file:");
    s_gets(file_app, SLEN);

    // 处理找不到目标文件
    if ((fa = fopen(file_app, "ab+")) == nullptr)
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }

    // 找到了目标文件，开辟一个缓存区(满刷新) 用于接受源文件的内容
    if (setvbuf(fa, nullptr, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    // 输入每一个目标文件的名字
    puts("Enter name of first source file (empty line to quit):");
    // 用户输入了文件名且输入的内容不为空
    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        // 目标文件和源文件内容一样
        if (strcmp(file_src, file_app) == 0)
            fputs("Can't append file to itself\n", stderr);

        // 源文件不存在
        else if ((fs = fopen(file_src, "rb")) == nullptr)
            fprintf(stderr, "Can't open %s\n", file_src);

        else
        {
            // 开辟一个缓存区，存储源文件数据，同时进行防止 cache 开辟失败的处理
            if (setvbuf(fs, nullptr, _IOFBF, BUFSIZE) != 0) {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);     /* 源文件缓存区内容添加到目标文件缓存区 */

            /* 缓存区读取报错 */
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", file_app);

            fclose(fs);
            files++;    // 成功把目标文件内容添加到源文件中，记数 + 1
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }

    // 展示成功添加的源文件的内容（添加至目标文件的内容）
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", file_app);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);
}

// 源文件缓存区内容添加到目标文件缓存区
void append(FILE *source, FILE *dest) {
    size_t bytes;
    static char temp[BUFSIZE];    // 只分配一次
    // 把源文件文件缓存区的内容拷贝到目标文件缓存区
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        // 注意这里的 byte 是指定写入多少个
        fwrite(temp, sizeof(char), bytes, dest);
}


// 处理输入文件名的时候过长或换行的问题
char * s_gets(char * st, int n) {
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');     // 查找换行符
        if (find)                          // 如果地址不是NULL，
            *find = '\0';                  // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

#endif //MAIN_CPP_二进制IO_H
