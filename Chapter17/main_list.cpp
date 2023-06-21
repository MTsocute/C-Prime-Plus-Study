//
// Created by Momo on 2023/6/22.
//

/* films3.c -- 使用抽象数据类型（ADT）风格的链表 */
/* 与list.c一起编译                        */
#include <cstdio>
#include <cstdlib>    /* 提供exit()的原型 */
#include <cstring>
#include "list.h"      /* 定义List、Item   */

void showmovies(Item item);

char *s_gets(char *st, int n);

int main() {
    List movies;
    Item temp;

    /* 初始化       */
    InitializeList(&movies);
    // 检测链表是否满了
    if (ListIsFull(&movies)) {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }

    /* 获取用户输入并储存 */
    puts("Enter first movie title:");
    // while 这里完成了一个新的 node 数据的初始化
    while (s_gets(temp.title, TSIZE) != nullptr && temp.title[0] != '\0') {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;
        // 检测是否可以添加新的节点
        if (AddItem(temp, &movies) == false) {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if (ListIsFull(&movies)) {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }

    /* 显示链表中的数据 */
    if (ListIsEmpty(&movies))
        printf("No data entered. ");
    else {
        printf("Here is the movie list:\n");
        // 第二个参数是一个函数指针
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));

    /* 清理         */
    EmptyTheList(&movies);
    printf("Bye!\n");

    return 0;
}

void showmovies(Item item) {
    printf("Movie: %s  Rating: %d\n", item.title,
           item.rating);
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');    // 查找换行符
        if (find)                   // 如果地址不是 NULL，
            *find = '\0';           // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}