//
// Created by Momo on 2023/5/23.
//

#ifndef MAIN_CPP_字符串函数_H
#define MAIN_CPP_字符串函数_H
#include <cstdio>
#include <cstring>  /* 包含一些字符串处理所需要的函数 */
#include <stdlib.h> /* atoi() 转换 string数字 为 int */

#define LIM 5
#define MAX 10
#define SIZE 80
#define LISTSIZE 6


/* 二合一函数，接受两个字符串，第一个字符串变成新的字符串 */
void use_of_strcat() {
    char flower[SIZE] = "You are so cool~";
    char addon [] = "Indeed.";
    strcat(flower, addon);
    puts("注意，flower 内容变多了 + addon");
    puts(flower);
}

/* strcat()函数不会检测前面数组的空间是否够用的情况，会造成溢出 */
// 为了解决溢出的问题，我们更多考虑使用 strncat(str1, str2, limit) 函数
void use_of_strnact() {
    // 第三个参数限制了str2可以添加到str1字符的数量
    char flower[SIZE] = "You are so cool~";
    char addon [] = "Indeed.";
    strncat(flower, addon, 3);

    puts(flower);
}


/* 做比较的函数
 * strcmp(str1, str2)
 * 相同返回 0，不同返回非0值
 * */
void use_of_strcmp() {
    const char * p1 = "loveyourfor3000";
    const char * p2 = "loveyourforU300";

    if (strcmp(p1, p2) == 0)
        printf("True");
    else
        printf("False");
}


// 如果 strcmp 比较的值不同，那么返回什么呢？
void return_of_strcmp() {
    printf("strcmp(\"A\", \"A\") is ");
    printf("%d\n", strcmp("A", "A"));

    /* 通过观察我们不难发现，是比较前后的 ASCII 大小决定返回的
     * 前面大就是 1
     * 后面大就是 -1
     * */
    printf("strcmp(\"A\", \"B\") is ");
    printf("%d\n", strcmp("A", "B"));

    printf("strcmp(\"B\", \"A\") is ");
    printf("%d\n", strcmp("B", "A"));

    printf("strcmp(\"C\", \"A\") is ");
    printf("%d\n", strcmp("C", "A"));

    // 我们想知道一不一样的时候返回结果是多少其实无所谓
    // 但是如果我们想知道两个字符ASCII，谁在前，谁在后面返回值正负就很有用了
    printf("strcmp(\"Z\", \"a\") is ");
    printf("%d\n", strcmp("Z", "a"));

    /* 这个情况不太一样，如果前几个一样就一一比较直到出现不同 */
    printf("strcmp(\"apples\", \"apple\") is ");
    printf("%d\n", strcmp("apples", "apple"));
}


/* 比较指定个数内个数的函数
 * strncmp(str1, str2, 5)
 * 字符不是如果前面有一样的就一直比下去吗，那么我们可以用这个函数限定比较个数
 * */
void use_of_strncmp() {
    const char * list[LISTSIZE] = {
        "astronomy",
        "astounding",
        "astrophysics",
        "ostracize",
        "asterism",
        "astrophobia"
    };
    int count = 0;
    int i;

    // 找出字符串开头部分是 astro 的单词的数量
    for (i = 0; i < LISTSIZE; i++)
        if (strncmp(list[i], "astro", 5) == 0) {
            printf("Found: %s\n", list[i]);
            count++;
        }
    printf("The list contained %d words beginning"
           " with astro.\n", count);
}


/* 拷贝的函数
 * strcpy() 和 strncpy()
 * */
// 我们字节看使用的demo main_function()
char * s_gets(char * st, int n);

void use_of_strcpy() {
    char qwords[LIM][SIZE];
    char temp[SIZE];
    int i = 0;

    printf("Enter %d words beginning with q:\n", LIM);
    // 要输入5个词，且不可以输入空内容
    while (i < LIM && s_gets(temp, SIZE)) { /* 注意这里是一个暂时的数组 */
        if (strncmp(temp, "q" ,1) != 0)     // if (temp[0] != 'q')
            printf("%s doesn't begin with q!\n", temp);
        else
        {   // 符合要求，拷贝过来
            strcpy(qwords[i], temp);
            i++;
        }
    }
    puts("Here are the words accepted:");
    for (i = 0; i < LIM; i++)
        puts(qwords[i]);

}

// 我们不一定要从开头拷贝，可以指定位置后面部分拷贝
void partial_strcpy() {
    const char * orig = "beast";
    char copy[SIZE] = "Be the best that you can be.";
    char * ps;

    // 指针指向字符串的第八个位置之后都改成 orig 内容
    ps = strcpy(copy + 7, orig);
    puts(copy);
    puts(ps);   // 返回的指针指向第一个参数的首地址
}

// 指定拷贝数量，更加安全
void use_of_strncpy() {
    const char * orig = "beast";
    char copy[SIZE] = "Be the best that you can be.";
    char * ptr;

    // 注意能不能拷贝到'\0'，如果拷贝不到那就会一部分替换了
    ptr = strncpy(copy+7, orig, 3);
    puts(copy);
    puts(ptr);
}

void use_of_sprintf() {
    double prize = 3e10;
    char first[MAX] = "Hello";
    char last[MAX] = "World";

    char formal[50];

}

void use_of_strchr() {
    const char *str = "Hello, World!";
    char ch = 'W';

    // 使用 strchr() 查找字符位置
    const char * result = strchr(str, ch);

    if (result != nullptr) {
        printf("Character '%c' found at position: %ld\n", ch, result - str);
    } else {
        printf("Character '%c' not found in the string.\n", ch);
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

// 我们可以使用 string.h 自带的 strchr() 平替我们实现的 s_gets()
void use_of_strchr_replace_s_gets() {
    char line[80];
    char * find;

    fgets(line, 80, stdin);
    find = strchr(line, '\n');    // 查找换行符，找到了就返回指向那个位置的一个指针
    if (find)                           // 如果没找到换行符，返回 nullptr
        *find = '\0';                   // 把该处的字符替换为空字符”
}

// atoi 转字符串数字为 int 数字
void useOfAtoi() {
    char  str1[10] = "123";
    char  str2[10] = "123hello";
    char  str3[10] = "hello";
    char  str4[10] = "hello123";

    /* 若果使用的函数是 string 123 就会直接转变没问题
     * 但是如果混杂字符串的，要分类讨论
        * 数字字符串在首部，就会返回数字
        * 如果首部没有数字字符串，就会返回 0
        * 如果字符串的尾部，也是返回 0
     * */
    int a = atoi(str1);
    int b = atoi(str2);
    int c = atoi(str3);
    int d = atoi(str4);


    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a,b,c,d);
}


#endif //MAIN_CPP_字符串函数_H
