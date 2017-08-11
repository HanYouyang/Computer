//
//  main.cpp
//  编程题＃2：能被3，5，7整除的数
//
//  Created by CYC on 8/8/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    while (cin >> n) {
        if( n % 3 == 0 && n % 5 == 0 && n % 7 == 0){
            cout << "3 5 7" << endl;
        }
        if(n % 3 == 0 && n % 5 == 0 && n % 7 != 0){
            cout << "3 5" << endl;
        }
        if(n % 3 == 0 && n % 5 != 0 && n % 7 == 0) {
            cout << "3 7" << endl;
        }
        if( n % 3 == 0 && n % 5 != 0 && n % 7 != 0){
            cout << "3" << endl;
        }
        if(n % 3 != 0 && n % 5 == 0 && n % 7 == 0) {
            cout << "5 7" << endl;
        }
        if( n % 3 != 0 && n % 5 == 0 && n % 7 != 0){
            cout << "5" << endl;
        }
        if( n % 3 != 0 && n % 5 != 0 && n % 7 != 0){
            cout << "n" << endl;
        }
        if( n % 3 != 0 && n % 5 != 0 && n % 7 == 0){
            cout << "7" << endl;
        }
    }
    
    
    
    return 0;
}