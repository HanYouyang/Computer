//
//  main.cpp
//  编程题＃4：最大奇数与最小偶数之差的绝对值
//
//  Created by CYC on 7/27/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int a[6];
    for ( int i = 0; i < 6; i++) {
        cin >> a[i] ;
    }
    
    int max_jishu = 0; // max_jishu 是 最大奇数
    int min_oushu = 101; // min_oushu 是 最小偶数
    
    for (int i = 0; i < 6; i++) {
        if ( a[i] % 2 == 0) {
            if ( min_oushu > a[i]){
                min_oushu = a[i];
            }
        }
    }
    
    for ( int i = 0; i < 6; i++) {
        if ( a[i] % 2 != 0) {
            if ( max_jishu < a[i]) {
                max_jishu = a[i];
            }
        }
    }
    
    int jueduizhi = 0; //jueduizhi 是 绝对值
    jueduizhi = abs(min_oushu - max_jishu );
    
    
    cout << jueduizhi << endl;
    return 0;
}