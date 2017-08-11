//
//  main.cpp
//  编程题＃1： 完美覆盖
//
//  Created by CYC on 12/6/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    for( int k = 0; k < 2012313141; k++){
        int n;
        cin >> n;
    
        if(n == -1){
            break;
        }
        if( n == 0 ){
            int c  = 1;
            cout << c << endl;
            continue;
        }
        if( n%2 != 0 ){
            int a  = 0;
            cout << a << endl;
            continue;
        }
        if(n / 2 == 1){
            int b = 3;
            cout << b << endl;
            continue;
        }
        else{
            int f[32] = {0};
            int sum[32] = {0};

            int m = n/2;
            f[1] = 3;
            sum[1] = 3;
            for( int i = 2; i <= m; i++){
                
                f[i] = f[i-1] + 2*sum[i-1] + 2;
                sum[i] = sum[i - 1] +f[i];
            }
            cout << f[m] << endl;
            
        }
    }
    
    
    
    return 0;
}



