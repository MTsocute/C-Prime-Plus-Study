//
// Created by Momo on 2023/6/20.
//

/* 像这种选择导入何种头文件就是移植的关键
 * 譬如说不同的操作系统，不同的架构的处理器，选择不同类型的数据处理
 * 这就是移植的关键
 * */

//#define COW 10    -->     决定走向的常量声明
// 如果使用 #define 定义了 COW 那就会倒入 cow.h 头文件，
#ifdef COW
    #include "cow.h"
    void cow_say() {
        puts("life is fucking moive!");
    }
// 如果没有订阅 COW 这个常量就会用 else 语句的
#else
    #include "条件编译/horse.h"
    void horse_say() {
        puts("life is fucking moive!");
    }
#endif

/* 使用 #ifdef 实现调试程序 */
#define JUST_CHECKING
#define LIMIT 4
void ifdef_debug() {
    int i;
    int total = 0;

    for (i = 1; i <= LIMIT; i++)
    {
        total += 2 * i*i + 1;
    // 调试开启或关闭的开关
    #ifdef JUST_CHECKING
        printf("i=%d, running total = %d\n", i, total);
    #endif
    }
    printf("Grand total = %d\n", total);
}
