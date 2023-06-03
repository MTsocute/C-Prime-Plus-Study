//
// Created by Momo on 2023/5/31.
//

#include "随机函数和静态变量.h"
#include "分配内存.h"

static unsigned int next = 1;

/* 生成伪随机数的魔术公式 */
unsigned int rand0() {
    next = next * 1103515245 + 12345;
    /* (next / 65536) % 32768 解释
     * unsigned int 大小是 32 位 65536 就是 2^16
     * 1. 2^32 / 2^16 相当于只要前面的 16 位
        * 二进制不好理解，我们拿十进制打比方
        * 1.38 * 10^3 / 1 * 10^2 = 13.8 只会取 13
     * 2. 2^16 % 2^16 相当于只取最后的 15位
        * 1.38 10^3 * 1 * 10^2 =
     * 根据无符号数的性质：
        * 范围限定在 0 ~ 32767 (2^0 ~ 2^15-1)
     * */
    return (unsigned int) (next / 65536) % 32768;
}

/* 改变 next 的值，实现不同的随机值 */
void srand1(unsigned int seed) {
    next = seed;
}

/* 生成会自己变动的随机值 */
void random_number() {
    /* 初始化种子
     * time 是 time_t 类型，所以我们要得要自己想要的得 () 强转
     * */
    unsigned int random = (unsigned int) time(nullptr);

    printf("random number is %u", random);
    srand1(random);
}
