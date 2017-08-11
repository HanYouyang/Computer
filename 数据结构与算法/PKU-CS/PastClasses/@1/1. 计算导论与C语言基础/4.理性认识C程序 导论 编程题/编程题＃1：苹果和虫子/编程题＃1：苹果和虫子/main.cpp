//
//  main.cpp
//  编程题＃1：苹果和虫子
//
//  Created by CYC on 7/25/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int num = 0;
    cin >> n >> x >> y;
    
    z = ceil(double(y) / double(x));
    if ( n -z >= 0) {
        num = n - z;
    }
    else {
        num = 0;
    }
    cout << num << endl;
    return 0;
}