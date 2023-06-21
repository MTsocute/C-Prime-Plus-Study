//
// Created by Momo on 2023/6/21.
//

#ifndef C_LEARNING_内联函数_H
#define C_LEARNING_内联函数_H
#include <cstdio>
#include <cstdlib>

// 我平时为了方便看都是在头文件中字节实现代码的，这个是不对的
// 我们应该声明在头文件，实现在源文件。
// 但是内联函数是一个例外，但是非多个文件都要用的时候，都用于源文件的多
inline static void eatline() {
    while (getchar() != '\n')
        continue;
}

#endif //C_LEARNING_内联函数_H
