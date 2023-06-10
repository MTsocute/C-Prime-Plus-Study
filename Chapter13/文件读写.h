//
// Created by Momo on 2023/6/6.
//

#ifndef MAIN_CPP_文件读写_H
#define MAIN_CPP_文件读写_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define CNTL_Z '\032'        /* DOS文本文件中的文件结尾标记 */
#define SLEN 81

/** 用法：程序名 文件所在地址
 *  作用：读取文件内容并返回文件中字符个数
 **/
void count_character_of_file(int argc, char * argv[]) {
    int ch;            // 读取文件时，储存每个字符的地方
    FILE *fp;          // “文件指针”
    unsigned long count = 0;

    // 参数不到 2个，用法不正确
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 处理文件不存在的时候
    if ((fp = fopen(argv[1], "r")) == nullptr) {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (
            (ch = getc(fp))     // 从文件中取到一个字符
            != EOF)
    {
        putc(ch, stdout);       // 把字符 ch 放入指定文件中
        count++;
    }

    if(fclose(fp) != EOF)     // 关闭文件检测
        printf("文件已关闭\n");
    else
        printf("文件关闭出现错误\n");

    printf("File %s has %lu characters\n", argv[1], count);
}


/** 该函数用于展示 fseek() 和 ftell() 的用法
 * 函数实现：
    * 让整个文件里面的字符全部倒转过来
 * 效果：
    * 文件内容是：123
    * 123 ---> 321
 * */
void reverse() {
    char file[SLEN],    // 文件名
    path[SLEN] = "/Users/momo/Desktop/C/Chapter13/data/";    // 文件存放路径
    char ch, *file_path;
    FILE *fp;
    long count, last;

    puts("Enter the name of the file to be processed:");
    scanf("%80s", file);    // 输入文件名

    file_path = strncat(path,file, 81);

    if ((fp = fopen(file_path, "rb")) == nullptr) {                                       /* 只读模式    */
        printf("reverse can't open %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);                /* 定位到文件末尾 */
    last = ftell(fp);                       /* 获取文件的大小 */
    for (count = 1L; count <= last; count++) {
        fseek(fp, -count, SEEK_END);        /* 回退往前读取字符串 */
        ch = (char )getc(fp);
        /* 只要读取的不是文件结束符，就输出 */
        if (ch != CNTL_Z && ch != '\r')
            putchar(ch);
    }

    putchar('\n');
    fclose(fp);
}

/* 使用 fscanf() fprintf() rewind() */
void use_of_fprint_fscanf_rewind()
{
    char arr[41];
    FILE *fp;

    fp = fopen("/Users/momo/"
               "Desktop/C/Chapter13/data/nihao.txt", "w+");

    if (fscanf(stdin, "%40s", arr) ==1 ) {
        fprintf(fp, "%s\n", arr);
        printf("Done!\n");
    } else printf("Check your input plz!");

    rewind(fp);
    puts("Content of the file:");
    while (fscanf(fp, "%s", arr) == 1)
        puts(arr);
    fclose(fp);
}

// 利用 getc() 读取文件
void readfile_getc()
{
    char ch;
    FILE *fp;

    fp = fopen("/Users/momo/"
               "Desktop/C/Chapter13/data/nihao.txt", "r");

    if (fp == nullptr) {
        printf("Can't open file!\n");
        exit(EXIT_FAILURE);
    }

    puts("Content of the file:");

    while ((ch = (char )getc(fp)) != EOF)
        printf("%c", ch);
    printf("\n");

    fclose(fp);
}

#endif //MAIN_CPP_文件读写_H