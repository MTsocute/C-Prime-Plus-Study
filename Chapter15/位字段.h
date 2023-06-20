//
// Created by Momo on 2023/6/19.
//

#ifndef C_LEARNING_位字段_H
#define C_LEARNING_位字段_H

#include <cstdio>
#include <cstdlib>

// 定义一个 位字段(bit field)
struct      // 隐式的写法，没有创建一个用于实现的属性，而是字节创建了一个变量
{   // 别管标签名，乱打的
    unsigned int asdasf: 1;
    unsigned int nasndi: 1;
    unsigned int asjibd: 1;
    unsigned int qiwueb: 1;
} prnt;


/* [: width] 用于声明这个成员变量的位大小，也就是所占的位是多少
    * int 原本是 4 个字节，也就是 32 位，但是我们这里使用了 : 16
    * 那么 bs1 & bs2 虽然是 32 位的int，但是实际上只用了 16 位（2字节）
    * 所以整个位字段的大小是 4 个字节
 * */
typedef struct tagBinst1    // 这个用于创建位字段
{
    int bs1: 16;
    int bs2: 16;
} Binst_1;

// 用于和下面的做对比
struct {
    // 虽然限制了宽度是 1b，但是每一块的存储大小仍然是 1B
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
} stuff0;   // --> 12 byte

// 位字段的大小不能小于所用数据类型的最小单位
// 分块是按照结构体的分块规则，按照最大类型来分块，不满一块，填充成那块的大小。超了就强制分成两块。
// 但是我们是按照 bit 切就更小了，但是块还是那个块。
struct {
    // 总数不到其声明类型位数大小
    unsigned int field1: 1;
    unsigned int field2: 1;
    unsigned int field3: 1;
} stuff1;   // --> 4 byte

struct {
    unsigned int field1: 1;
    unsigned int       : 2; // 决定了结构体对齐大小块大小是 2bit
    unsigned int field2: 1;
    /* 上面三个也达不到最小本身类型位数需求，所以作为填充成4字节 */
    unsigned int       : 0; // 强制换到下一个块
    unsigned int field3: 1; // 虽然强制换块了，但是不够最小本身类型位数，就填充成那么多
} stuff2;   // --> 8 byte

// unsigned int :0 可以造成强制换块
// 尽管原来的块存储的下，但是也会被移动到下一个块中
// 对比 stuff2 和 stuff3 就知道了
struct {
    unsigned int field1: 1;
    unsigned int       : 2;
    unsigned int field2: 1;
    unsigned int field3: 1;
} stuff3;   // --> 4 byte


// namespace 解决函数名称重复冲突问题
namespace bit_field {
    // 展示结构体和位字段的大小决定的差异
    void show_size() {
        // 结果是 0
        printf("Size of stuff0 is %lu\n", sizeof stuff0);
        // 结构是 4
        printf("Size of stuff1 is %lu\n", sizeof stuff1);
        // 结果是 8
        printf("Size of stuff2 is %lu\n", sizeof stuff2);
        // 结构是 4
        printf("Size of stuff3 is %lu\n", sizeof stuff3);
    }
}

#endif //C_LEARNING_位字段_H
