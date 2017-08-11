//
//  main.cpp
//  编程题＃3：最高的分数
//
//  Created by CYC on 7/27/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main () {
    int n = 0; int a[100];
    cin >> n;
    for ( int i = 0; i < n; i++) {
        cin >> a[i];

    }
    
    int max = 0;
    for ( int j = 0; j < n; j++) {
        if ( max < a[j]) {
            max = a[j];
           }
        
    }
    
    cout << max << endl;
    
    
    
    return 0;
}