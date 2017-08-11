//
//  main.cpp
//  编程题＃3：整数的个数
//
//  Created by CYC on 7/24/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int k = 0;
    cin >> k;
    
    int a[100];
    for (int i = 0; i < k; i++){
        cin >> a[i];
    }
    
    int num1 = 0;
    for ( int j = 0; j < k; j++){
        if ( a[j]==1 ){
            num1 = num1 + 1;
        }
    }
    
    int num5 = 0;
    for ( int j = 0; j < k; j++){
        if ( a[j]==5 ){
            num5 = num5 + 1;
        }
    }

    int num10 = 0;
    for ( int j = 0; j < k; j++){
        if ( a[j]==10 ){
            num10 = num10 + 1;
        }
    }

    cout << num1 << endl << num5 << endl << num10 <<endl;
    
    return  0;
}