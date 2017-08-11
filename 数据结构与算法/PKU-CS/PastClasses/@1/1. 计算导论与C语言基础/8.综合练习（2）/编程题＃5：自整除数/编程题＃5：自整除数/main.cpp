//
//  main.cpp
//  编程题＃5：自整除数
//
//  Created by CYC on 8/1/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    int n = 0;
    cin >> n;
    
    int m = 0;
    m = n/10 + n%10;
    
    for( int i = 10; i <= n; i++){
        m = i/10 + i%10;
        if ( i % m == 0){
            cout << i << endl;
        }
    }
    
   
    
    
    return 0;
}
