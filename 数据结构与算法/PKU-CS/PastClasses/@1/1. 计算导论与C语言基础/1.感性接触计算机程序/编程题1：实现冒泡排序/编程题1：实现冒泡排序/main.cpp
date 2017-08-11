//
//  main.cpp
//  编程题1：实现冒泡排序
//
//  Created by CYC on 7/23/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int n, a[1000]; // 一共n个数，n不超过1000。a用来保存这些数
    cin >> n;
    // 输入n个数
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 冒泡，不断比较相邻的两个数，如果顺序错了，那么就交换
    for ( int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n- i; j++){
            if (a[j-1] > a[j]) {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    // 依次输出
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    
    return 0;
}
