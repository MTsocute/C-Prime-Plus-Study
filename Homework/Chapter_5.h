//
// Created by Momo on 2023/4/30.
//

#ifndef MAIN_CPP_PRACTISE5_H
#define MAIN_CPP_PRACTISE5_H
#include <stdio.h>

void Cp5_1() {
    int const hour_unit = 60;
    int hour;
    int min;
    int time = 0;

    printf("请任意输入一个分钟单位下的时间，程序会将其转换成对应 小时+分钟：");
    scanf("%d", &time);

    printf("Time = %d\n", time);


    while (time) {
        if (time <=0) {
            time = 0;
        }
        else {
            hour = time / hour_unit;
            min = time % hour_unit;
            printf("对应：%d小时 %d分钟\n", hour, min);
            printf("请任意输入一个分钟单位下的时间，程序会将其转换成对应 小时+分钟：");
            scanf("%d", &time);
        }
    }
}

void Cp5_2() {
    int add_ten = 0;
    int ini_num = 0;

    printf("请任意输入一个数：");
    scanf("%d", &ini_num);

    add_ten = ini_num + 10;
    while(ini_num <= add_ten) {
        printf("%d ", ini_num);
        ini_num++;
    }
}

int Cp5_7(double num) {
    double cube = num * num * num;
    return cube;
}

void Cp5_8(int a, int b) {
    while(b) {
        if(b < 0) {
            break;
        }
        else {
            printf("%d %% %d = %d\n", b, a, b % a);
            printf("input a number <= 0 to quit:");
            scanf("%d", &b);
        }
    }
}


void Cp5_9(double hua_temp) {
    const double SHE = 32.0;
    const double KAI = 273.16;
    double She_temp, Kai_temp;


    She_temp = 5.0 / 9.0 * (hua_temp - SHE);
    Kai_temp = She_temp + KAI;

    printf("华氏度:%le\n", hua_temp);
    printf("摄氏度:%le\n", She_temp);
    printf("开氏度:%le\n", Kai_temp);

}

#endif //MAIN_CPP_PRACTISE5_H
