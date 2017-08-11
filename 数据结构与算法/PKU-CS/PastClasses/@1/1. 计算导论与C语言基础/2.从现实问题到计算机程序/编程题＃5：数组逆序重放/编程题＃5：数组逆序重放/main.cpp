//
//  main.cpp
//  编程题＃5：数组逆序重放
//
//  Created by CYC on 7/25/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main () {
    int N = 0; int a[100];
    cin >> N;
    
    
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    for ( int j = N-1; j >= 0; j--){
        cout<< a[j]<< " ";
    }
    
    
    
    return 0;
}