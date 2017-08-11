//
//  main.cpp
//  编程题＃5：分离整数的各个数位
//
//  Created by CYC on 7/27/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main () {
    int x = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    cin >> x;
    
    a = int (x / 100);
    b = int (x / 10) - 10 * a;
    c = x - 100 * a - 10 * b ;
    
    cout << a << endl << b << endl << c << endl;
    
    
    
    
    
    return 0;
}