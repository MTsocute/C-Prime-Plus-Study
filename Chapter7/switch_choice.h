//
// Created by Momo on 2023/5/7.
//

#ifndef MAIN_CPP_SWITCH_CHOICE_H
#define MAIN_CPP_SWITCH_CHOICE_H
#include <stdio.h>

// 多重标签
void multi_case() {
    char ch;
    int a_ct, e_ct, i_ct, o_ct, u_ct;

    a_ct = e_ct = i_ct = o_ct = u_ct = 0;

    printf("Enter some text; enter # to quit.\n");
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
            // 无论是走 a A 都会走到这这个：相当于 case (a || A):
            case 'a':
            case 'A':  a_ct++;
                break;

            case 'e':
            case 'E':  e_ct++;
                break;

            case 'i':
            case 'I':  i_ct++;
                break;

            case 'o':
            case 'O':  o_ct++;
                break;

            case 'u':
            case 'U':  u_ct++;
                break;

            default:   break;
        }                        // switch结束
    }                            // while循环结束

    printf("number of vowels:   A    E    I    O    U\n");
    printf("              %4d %4d %4d %4d %4d\n",
           a_ct, e_ct, i_ct, o_ct, u_ct);
}

#endif //MAIN_CPP_SWITCH_CHOICE_H
