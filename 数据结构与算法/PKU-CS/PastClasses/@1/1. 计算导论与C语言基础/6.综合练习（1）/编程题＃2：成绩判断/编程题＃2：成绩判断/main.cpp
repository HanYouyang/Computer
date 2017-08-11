//
//  main.cpp
//  编程题＃2：成绩判断
//
//  Created by CYC on 7/29/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    
    if ( n <= 100 && n >=95 ) {
        cout << "1" << endl;
    }
    else if (n < 95 && n >=90 ) {
        cout << "2" << endl;
    }
    else if (n < 90 && n>= 85 ) {
        cout << "3" << endl;
    }
    else if (n < 85 && n>= 80) {
        cout << "4" << endl;
    }
    else if (n < 80 && n>= 70) {
        cout << "5" << endl;
    }
    else if (n < 70 && n>= 60) {
        cout << "6" << endl;
    }
    else if (n < 60) {
        cout << "7" << endl;
    }
    
    return 0;
}