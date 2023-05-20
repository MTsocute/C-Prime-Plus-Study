//
// Created by Momo on 2023/5/19.
//

#ifndef MAIN_CPP_多维数组和指针_H
#define MAIN_CPP_多维数组和指针_H
#include <cstdio>


// 我们可以理解为：1 个二级指针下面 4 个一级指针
int zippo[4][2] = {
    { 2, 4 },
    { 6, 8 },
    { 1, 3 },
    { 5, 7 }
};

/* 结合 713 页一起看 */
void multi_dim_move() {
    /*
     * 通过比较不难发现，zippo 和 zippo[0] 都指向首地址
     * 但是，zippo + 1 和 zippo[0] + 1 移动所需字节全然不同
     * 因为 zippo 指向是两个 int 一级指针的 int 指针（二级指针）
     * 同单位移动需要跨越自身那么多的字节，既即：两个 int 字节
     * zippo[0] 就是一级指针的数组的理解
     * */
    printf("   zippo = %p,    zippo + 1 = %p\n", zippo, zippo + 1);
    printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);
    /*
     * 按照我们二级指针的理解呢，zippo 囊括着 4个数组指针
     * *zippo 就是第一个指针 指向 {2, 4}
     * 所以 *zippo + 1 自然就是一级指针的移动了，就是里面元素的移动占 一个 int
     * */
    printf("  *zippo = %p,   *zippo + 1 = %p\n",*zippo, *zippo + 1);
}

void multi_dim_address(){
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    printf("  *zippo[0] = %d\n", *zippo[0]);
    printf("    **zippo = %d\n\n", **zippo);
    printf("      zippo[2][1] = %d\n", zippo[2][1]);
    /*
     * 我们关注下这个：*(*(zippo + 2) + 1))
     * zippo + 2：相当于二级指针移动两个位置 也就是第一层的 zippo[2][x]
     * 我们 *(zippo + 2)：相当于打开移动移动两位位置的一级指针
     * 也就是指向 {1, 3} 的指针被解引用了
     * 我们这里假定为 int *zip = {1,3}
     * 然后我们对 *(zip + 1) 就是移动了一个位置获取那个位置的值，也就是第二层的 zippo[2][1]
     * 当然，我们 *(zippo + 2) 看为 zip 之后不也是一个数组指针嘛，我们也可以 zip[1] 的
     * */
    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo + 2) + 1));
    printf("*(zippo + 2)[1]   = %d\n", (*(zippo + 2))[1]);
}

#endif //MAIN_CPP_多维数组和指针_H
