//
// Created by Momo on 2023/5/7.
//

#ifndef MAIN_CPP_GOTO_H
#define MAIN_CPP_GOTO_H
#include <cstdio>

// Without goto
void if_without_goto() {
    int a, x;
    scanf("%d", &a);
    x = (a >= 0) ? 5 : 6;
    printf("x = %d\n", x);
}

void goto_demo() {
    int a, x;
    scanf("%d", &a);

    if (a >= 0) {
        goto state_a;
    } else {
        goto state_b;
    }

    state_a:
    x = 5;
    printf("x = %d\n", x);
    goto end;

    state_b:
    x = 6;
    printf("x = %d\n", x);

    end:
    return;
}




#endif //MAIN_CPP_GOTO_H
