//
//  main.cpp
//  编程题＃1：含k个3的数
//
//  Created by CYC on 10/21/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    int m = 0;
    int k =0;
    cin >> m >> k;
    
    if( m % 19 == 0){
        int num = 0;
        for( int i = 0; i < 10; i++){
            int s = m % 10;
            if( s == 3){
                num++;
            }
            m = int(m/10);
            if(m < 1){
                if(num == k){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
                break;
            }
        }
    }
    
    
    else{
        cout << "NO" << endl;
    }
    
    
    return 0;
}
