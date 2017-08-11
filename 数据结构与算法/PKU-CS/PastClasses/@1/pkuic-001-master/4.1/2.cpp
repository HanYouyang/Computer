/*
=====
第2题：2:大象喝水
=====

总时间限制:
    1000ms
内存限制:
    65536kB

描述
    一只大象口渴了，要喝20升水才能解渴，但现在只有一个深h厘米，底面半径为r厘米的小圆桶(h和r都是整数)。问大象至少要喝多少桶水才会解渴。(设PAI=3.14159)
输入
    输入有一行：分别表示小圆桶的深h，和底面半径r，单位都是厘米。
输出
    输出也只有一行，大象至少要喝水的桶数。
样例输入

    23 11

样例输出

    3
*/

#include<iostream>
using namespace std;

int main() {
    float PAI = 3.14159;
    float A = 20 * 1000;
    // n: 桶数
    int h = 0, r = 0, n = 0;
    // a: 一桶水的体积
    float a = 0;
    cin >> h >> r;

    a = PAI * r * r * h;
    n = A / a;
    if (n * a < A) {
        n++;
    }

    cout << n;

    return 0;
}
