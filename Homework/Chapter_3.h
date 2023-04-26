//
// Created by Momo on 2023/4/23.
//

#ifndef MAIN_CPP_CHAPTER_3_H
#define MAIN_CPP_CHAPTER_3_H
#include <cstdio>
// change number into corresponding Ascii Code
void Cp3_2() /*第三章的第二题练习题*/
{
    int number;
    printf("plz input the number:_______\b\b\b\b\b\b\b");
    scanf("%d", &number);
    if(number<=128&&number>31) {
        printf("Its ASCII is %c", number);
    }
    else { printf("Check your number plz");}
}

void Cp3_3() {
    printf("\aStartled by the sudden sound, Sally shouted\n");
    printf("\"By the Great Pumpkin, what was that!\"");

}

void Cp3_4(){
    float fl_a;
    printf("请输入一个浮点数:");
    scanf("%f", &fl_a);
    printf("%.2f\n", fl_a);
    printf("%f\n", fl_a);
    printf("%e\n", fl_a);
    printf("%a\n", fl_a);   // p记数法
}

void Cp3_5() {
    double year = 3.156e07;
    int age;
    printf("How old are you bitch:");
    scanf("%d", &age);
    printf("Your age is %d, and ts your age into seconds is %e", age, age * year);
}

void Cp3_6() {
    double Water_molecular_weight = 3e-23;
    double Quotuo = 950;
    printf("The mount of Water Molecular in a Quotuo is %e", Quotuo / Water_molecular_weight);
}

// if we use int
void Cp3_8_int()
{
    int pint, cup, ounce, tablespoon, teaspoon;
    printf("Give a number of cup:");
    scanf("%d", &cup);

    // 这里存在问题，因为 int 不会转换小数，更不会四舍五入，造成误差，所以要用 float
    printf("%d cup is %d pint\n", cup, pint = cup / 2);
    printf("%d cup is %d ounce\n", cup, ounce = 8 * cup);
    printf("%d cup is %d tablespoon\n", cup,tablespoon = 16 * cup);
    printf("%d cup is %d teaspoon\n", cup, teaspoon = 48 * cup);
}

// Use float to fix the problem
void Cp3_8_float()
{
    float pint, cup, ounce, tablespoon, teaspoon;
    printf("Give a number of cup:");
    scanf("%f", &cup);
    pint = cup / 2;
    ounce = 8 * cup;
    tablespoon = 16 * cup;
    teaspoon = 48 * cup;

    printf("%.0f cup is %.2f pint\n", cup, pint);
    printf("%.0f cup is %.2f ounce\n", cup, ounce);
    printf("%.0f cup is %.2f tablespoon\n", cup,tablespoon);
    printf("%.0f cup is %.2f teaspoon\n", cup, teaspoon);
}


#endif //MAIN_CPP_CHAPTER_3_H
