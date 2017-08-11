//
//  main.cpp
//  编程题＃2：奇数求和
//
//  Created by CYC on 7/24/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main () {
    int m = 0; int n = 0;
    cin >> m >> n;

    int sum = 0;
    for ( int i = m; i <= n ; i++){
        if ( i % 2 != 0 ) {
            sum = sum + i ;
        }
    }
    
    cout << sum <<endl;
    
    
    
    return 0;
}

