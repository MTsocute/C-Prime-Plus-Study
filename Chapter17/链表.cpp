//
// Created by Momo on 2023/6/22.
//

#include <cstdlib>
#include <cstdio>
#include <cstring>

#define TSIZE 45    /* 储存片名的数组大小*/

struct film {
    char title[TSIZE];
    int rating;
    struct film *next;
};


char *s_gets(char *st, int n);

int main() {
    struct film *head = nullptr;
    struct film *prev, *current;
    char input[TSIZE];

    /* 收集并储存信息 */
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != nullptr && input[0] != '\0') {   // 输入一个电影，分配一个结构和并指向新的结构
        current = (struct film *) malloc(sizeof(struct film));
        if (head == nullptr)        /* 第1个结构 */
            head = current;
        else                     /* 后续的结构 */
            prev->next = current;
        // 当前结构的指针设为 null 因为说不定这个一个结构就是最后一个结构
        current->next = nullptr;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

    /* 显示电影列表 */
    if (head == nullptr)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");
    current = head;
    while (current != nullptr) {
        printf("Movie: %s  Rating: %d\n",
               current->title, current->rating);
        current = current->next;
    }

    /* 完成任务，释放已分配的内存 */
    current = head;
    while (current != nullptr) {
        prev = current;  // 保存当前节点的指针
        current = current->next;
        free(prev);
    }
    printf("Bye!\n");
    return 0;
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