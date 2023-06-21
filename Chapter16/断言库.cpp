//
// Created by Momo on 2023/6/22.
//
/* assert.c -- 使用 assert() */

#define NDEBUG  // 这个用于关闭断言测试，要声明在断言头文件前

#include <cstdio>
#include <cmath>
#include <cassert>
#include <climits>

// assert() 是错误时，中断程序
void use_of_assert()
{
    double x, y, z;

    puts("Enter a pair of numbers (0 0 to quit): ");
    while (scanf("%lf%lf", &x, &y) == 2
           && (x != 0 || y != 0))
    {
        z = x * x - y * y;  /* 应该用 + */
        // assert() 里面一般都是一个表达式
        assert(z >= 0);
        printf("answer is %f\n", sqrt(z));
        puts("Next pair of numbers: ");
    }
    puts("Done");
}

// _Static_assert() 是错误时，不通过编译
void use_of_StaticAssert()
{
//    _Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
    puts("char is 16 bits.");
}


int main() {
    use_of_StaticAssert();
    return 0;
}
