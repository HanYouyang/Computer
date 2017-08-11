//
//  main.cpp
//  编程题＃4：人民币支付
//
//  Created by CYC on 7/30/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    int A = 0;
    cin >> A;
    int b[6] = {100, 50, 20, 10, 5, 1};
    for ( int i = 0; i < 6; i++) {
        cout << A/b[i] << endl;
        A = A % b[i];
    }
    
    
    return 0;
}
