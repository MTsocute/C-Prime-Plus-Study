//
// Created by Momo on 2023/5/2.
//

#ifndef MAIN_CPP_BOOL_H
#define MAIN_CPP_BOOL_H
#include <stdio.h>

void bool_demo() {
    long num;
    long sum = 0L;
    bool input_is_good;    // Bool 类型的数据，默认是 1

    printf("Please enter an integer to be summed ");
    printf("(q to quit): ");
    input_is_good = (scanf("%ld", &num) == 1);

    while (input_is_good) {
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        // 注意：Bool 是可以把逻辑判断的 True ｜ False，当值来赋的
        input_is_good = (scanf("%ld", &num) == 1);
    }
    printf("Those integers sum to %ld.\n", sum);
}

#endif //MAIN_CPP_BOOL_H
