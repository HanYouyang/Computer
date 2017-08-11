//
//  main.cpp
//  编程题＃2：大象喝水
//
//  Created by CYC on 7/25/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int h = 0;
    int r = 0;
    double v = 0; //水桶的体积
    int num = 0;  //至少要喝多少桶水
    cin >> h >> r;
    
    v = ((3.14159 * r * r * h) / 1000); //求体积，转化为升
    num = ceil (20 / v); //向上取整
    
    cout << num << endl;
    
    return 0;
}