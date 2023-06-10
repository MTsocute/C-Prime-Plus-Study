//
// Created by Momo on 2023/6/6.
//

#ifndef MAIN_CPP_REDUCE_SIZE_H
#define MAIN_CPP_REDUCE_SIZE_H
#include <cstdio>
#include <cstring>
#define LEN 40

/** 保留每3个字符中的第1个字符的方式压缩第1个文件的内容。
 * 最后，把压缩后的文本存入第2个文件。第2个文件的名称是第1个文件名加上.red 后缀
 * */
void reduce_file(int argc, char * argv[]) {
    FILE *in, *out;    // 声明两个指向 FILE 的指针
    int ch;
    char name[LEN];     // 储存输出文件名
    int count = 0;

    // 检查命令行参数
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 处理找不到文件
    if ((in = fopen(argv[1], "r")) == nullptr) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                argv[1]);
        exit(EXIT_FAILURE);
    }

    // 设置输出：LEN - 5 给文件后缀名留出空间
    strncpy(name, argv[1], LEN - 5);     // 拷贝文件名
    name[LEN - 5] = '\0';                       // 前面一个整体作为字符串，以便于 后面 strcat
    strcat(name, ".red");                // 在文件名后添加.red


    // 以写模式打开文件
    if ((out = fopen(name, "w")) == nullptr) {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    // 拷贝数据
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)   // 每三个字符选出来
            putc(ch, out);    // 字符串存储到 .red 文件

    // 处理文件关闭问题
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");
}



#endif //MAIN_CPP_REDUCE_SIZE_H
