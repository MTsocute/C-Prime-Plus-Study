//
// Created by Momo on 2023/4/30.
//

#ifndef MAIN_CPP_强制转换的演示案例_H
#define MAIN_CPP_强制转换的演示案例_H
#include <cstdio>

const int S_PER_M = 60;                // 1分钟的秒数
const int S_PER_H = 3600;              // 1小时的秒数
const double M_PER_K = 0.62137;        // 1公里的英里数

/* 换算跑步的平均时速：英里/每小时
 * 1、公里转换成英里
 * 2、所用时间，转换成小时
 * */
void enforce_demo() {
    double distk, distm;     // 跑过的距离（分别以公里和英里为单位）
    double rate;             // 平均速度（以英里/小时为单位）
    int min, sec;            // 跑步用时（以分钟和秒为单位）
    int time;                // 跑步用时（以秒为单位）
    double mtime;            // 跑1英里需要的时间，以秒为单位
    int mmin, msec;          // 跑1英里需要的时间，以分钟和秒为单位

    printf("This program converts your time for a metric race\n");      // 提示用户说，我们这个程序的功能
    printf("to a time for running a mile and to your average\n");       // 转换平均时速位，英里/每小时
    printf("speed in miles per hour.\n");
    printf("Please enter, in kilometers, the distance run.\n");     // 让用户输入：自己的所花时间和对应距离
    scanf("%lf", &distk);              // %lf表示读取一个double类型的值，读取用户跑的公里数
    printf("Next enter the time in minutes and seconds.\n");
    printf("Begin by entering the minutes.\n");
    scanf("%d", &min);      // 获取用户跑的分钟数
    printf("Now enter the seconds.\n");
    scanf("%d", &sec);      // 获取用户跑的秒数

    time = S_PER_M * min + sec;        // 把时间转换成秒
    distm = M_PER_K * distk;           // 把公里转换成英里
    rate = distm / time * S_PER_H;     // 英里/（用户所花的总秒数/一小时所需要的秒数 = 用户花了几个小时） --> 英里/小时

    /* 算出用户在该平均速率下，跑一公里需要花费的 分钟数、秒数 */
    mtime = (double) time / distm;     // 计算跑1英里需要花费的时间（以秒为单位），即花费的总秒数除以跑过的英里数。
    mmin = (int) mtime / S_PER_M;      // 求分钟数
    msec = (int) mtime % S_PER_M;      // 求出剩余的秒数

    printf("You ran %1.2f km (%1.2f miles) in %d min, %d sec.\n", distk, distm, min, sec);
    printf("That pace corresponds to running a mile in %d min, ", mmin);
    printf("%d sec.\nYour average speed was %1.2f mph.\n", msec, rate);
}



#endif //MAIN_CPP_强制转换的演示案例_H
