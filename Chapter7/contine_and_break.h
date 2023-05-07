//
// Created by Momo on 2023/5/7.
//

#ifndef MAIN_CPP_CONTINE_AND_BREAK_H
#define MAIN_CPP_CONTINE_AND_BREAK_H

// continue 在 while 循环的用法
void continue_in_while() {
    int count = 0;
    char ch;
    while (count < 10) {
        ch = getchar();

        if (ch == '\n')     // 如果是换行符是不会记数的
            continue;
        // 注意看这里的 continue 如果触发，后面的部分是不会跑的

        putchar(ch);
        count++;
        printf("Count = %d", count);
    }
}

void break_in_while() {
    int p, q;
    scanf("%d", &p);

    while (p>0) {
        printf("p = %d\n", p);
        scanf("%d", &q);

        while (q>0) {
            printf("p * q = %d\n", p*q);
            if(q>100)
                break;  // 内层循环
        }
        if (q>100)
            break;  // 外层循环

        printf("这里是不会被执行的！");
        scanf("%d", &q);
    }
}


#endif
