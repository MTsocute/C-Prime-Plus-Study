//
// Created by Momo on 2023/6/13.
//

#ifndef MAIN_CPP_结构体数据的文件写入_H
#define MAIN_CPP_结构体数据的文件写入_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL  40
#define MAXAUTL  40
#define MAXBKS   10             /* 最大书籍数量 */


char * s_gets(char * st, int n);

struct book {                   /* 建立 book 模板 */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void port_use()
{
    struct book library[MAXBKS];        /* 结构数组 */
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof(struct book);     /* 读写的时候告诉特定的结构体大小 */

    // 创建文件或打开存在文件处理
    if ((pbooks = fopen("/Users/momo/Desktop/C/Chapter14/data/book.dat",
                        "a+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);            /* 定位到文件开始 */

    // 读取书库中现存有图书，检查书库有没有满，并输出存有的书籍
    while (count < MAXBKS && fread(&library[count], size,
                                   1, pbooks) == 1)     // 读取一个结构体
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title,
               library[count].author, library[count].value);
        count++;    // 记录
    }

    filecount = count;  // filecount 就是书库中现存有书数量

    // 书本数量达到上限，就提示无法输入
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");

    // 写入新书的部分，如果回车就取消继续写入新书
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != nullptr
           && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);

        /* 清理输入行  */
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            puts("Enter the next title.");
    }

    // 如果用户有输入新的内容才写入
    if (count > 0)
    {
        puts("Here is the list of your books: ");
        for (index = 0; index < count; ++index)
            printf("%s by %s: $%.2f\n", library[index].title,
                    library[index].author, library[index].value);
        // 写入新的书籍
        // count - filecount 既是新增加了几个书的数量，并写入文件当中去
        fwrite(&library[filecount], size, count - filecount,
                pbooks);

    } else puts("No books? Too bad.\n");
    fclose(pbooks);
}


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


#endif //MAIN_CPP_结构体数据的文件写入_H
