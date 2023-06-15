//
// Created by Momo on 2023/6/13.
//

#ifndef MAIN_CPP_结构体成员变量是指针_H
#define MAIN_CPP_结构体成员变量是指针_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define SLEN 20

extern char * s_gets(char * st, int n);

struct namect {
    char * fname;
    char * lname;
    int letters;
};

void getinfo (struct namect * pst)
{
    char temp[SLEN];

    printf("Please enter your first name.\n");
    s_gets(temp, SLEN);
    // 分配内存储存名
    pst->fname = (char *) malloc(strlen(temp) + 1);
    // 把名拷贝到已分配的内存
    strcpy(pst->fname, temp);

    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);
    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}


void free_malloc(struct namect * pst) {
    free(pst->fname);
    free(pst->lname);
}

#endif //MAIN_CPP_结构体成员变量是指针_H
