//
// Created by Momo on 2023/4/26.
//

#ifndef MAIN_CPP_CHAPTER_4_H
#define MAIN_CPP_CHAPTER_4_H
#include <cstdio>
#include <string>

#define BOOK "War and Peace"

void Cp4_2() {
    // 虽然整数部分宽度不够，但是仍然会打出来
    printf("He sold the painting for $%2.2f.\n", 2.345e2);
    // e 转换成 double 而且，这个时候会四舍五入
    printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);
}

void Cp4_5() {
    float cost = 12.99;
    float percent = 80.0;

    printf("This copy of \"%s\" sells for $%.2f\n", BOOK, cost);
    printf("That is %0.f%% of list", percent);
}

void Cp4_6_7_8() {
    // 6: d、e
    printf("*%4X*\n", 138);     // 一定要大写的 X，不然字母是小写

    char name[30] = "1234567890abcd";
    printf("*%-30s*\n", name);
    printf("---------------------------------\n");

    // 7: b c d e
    int a = 138;
    printf("%#x\n", a);

    double b = 233;
    printf("*%-12.2E*\n", b);

    float c = 234.346;
    printf("*%+10.f*\n", c);

    printf("%8.8s\n", name);    // . 前面的 8 代表宽度，后面的 8 代表只输出8个字符

    // 8: a e
    printf("*%6.4d*\n", 124);   // 整数部分，如果有 . 那么.后要求的就是最少要有几个数字，不够的话，就会用0补在前
    printf("*%-7.5s*", name);
}


/* 这个部分的内容就是变成练习的部分 */

void cp48_1() {
    char sur[20], fam_name[20];
    printf("input your surname plz:");
    scanf("%s", sur);
    printf("input your family name plz:");
    scanf("%s", fam_name);
    printf("You name is %s,%s", sur, fam_name);
}

void cp48_3() {
    float f_num;
    float f_num_2;
    printf("请输入一个浮点数: ");
    scanf("%f", &f_num);

    // a
    printf("%.1f\t%.1e\n", f_num, f_num);

    // b
    printf("请输入一个浮点数: ");
    scanf("%f", &f_num_2);
    printf("%+.3f\t%.3e\n", f_num_2, f_num_2);

}

void cp48_5() {
    float download_time, size = 2.2, download_speed = 18.12;
    download_time = (size * 8) / download_speed;
    printf("At %.2f megabits per second, a file of %.2f megabytes\n"
           "downloads in %0.2f seconds.\n", download_speed, size, download_time);
}


#endif //MAIN_CPP_CHAPTER_4_H
