//
//  main.cpp
//  编程题＃1：判断闰年
//
//  Created by CYC on 8/8/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int a = 0;
    cin >> a;
    
    if( a % 4 == 0 && a % 100 != 0){
        cout << "Y" << endl;
    }
    else if (a % 400 == 0){
        cout << "Y" << endl;
    }
    else {
        cout << "N" << endl;
    }
    
    
    
    return 0;
}