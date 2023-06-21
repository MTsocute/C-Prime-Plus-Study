//
// Created by Momo on 2023/6/21.
//
#include <cstdio>
#include <cmath>

// PI = 4 * atan(1)~arctan(1)
#define RAD_TO_DEG (180/(4 * atan(1)))  // 1 弧度（基本单位）

typedef struct polar_v {
    double magnitude;
    double angle;
} Polar_V;

typedef struct rect_v {
    double x;
    double y;
} Rect_V;

Polar_V rect_to_polar(Rect_V);

int main() {
    Rect_V input;
    Polar_V result;

    puts("Enter x and y coordinates; enter q to quit:");
    while (scanf("%lf %lf", &input.x, &input.y) == 2)
    {
        result = rect_to_polar(input);
        printf("magnitude = %0.2f, angle = %0.2f\n",
               result.magnitude, result.angle);
    }
    puts("Bye.");

    return 0;
}

// 直角坐标转换极坐标
Polar_V rect_to_polar(Rect_V rv) {
    Polar_V pv;

    pv.magnitude = sqrt(pow(rv.x, 2) + pow(rv.y, 2));
    if (pv.magnitude == 0)
        pv.angle = 0.0;
    else
        // atan2 返回 y/x 的弧度，弧度 * 弧长单位 = 对应角度
        pv.angle = RAD_TO_DEG * atan2(rv.y, rv.x);
    return pv;
}
