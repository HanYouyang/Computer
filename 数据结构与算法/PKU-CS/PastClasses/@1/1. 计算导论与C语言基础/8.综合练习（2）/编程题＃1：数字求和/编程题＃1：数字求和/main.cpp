//
//  main.cpp
//  编程题＃1：数字求和
//
//  Created by CYC on 7/31/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int a = 0; int n[5];
    cin >> a >> n[0] >> n[1] >> n[2] >> n[3] >> n[4];
    
    
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        if(a > n[i]) {
            sum = sum + n[i];
        }
    }
    
    
    cout << sum << endl;
    
    return 0;
}