//
//  main.cpp
//  编程题＃6：循环移动
//
//  Created by CYC on 8/7/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int m = 0;
    int a[1000];
    cin >> n >> m;
    for( int i = 0; i < n; i++){
        cin >> a[i];
    }

    
    for( int i = 0; i < n; i++){
        int tem = i;
        if( tem >= m ){
            tem = tem -  m;
        }
        else if( tem < m){
            tem = tem + n - m;
        }
        
        
        cout << a[tem] <<" " ;
    }
    
    cout << endl;
    
    
    
    
    
    
    
    
    
    
    return 0;
}