//
//  main.cpp
//  编程题＃4：寻找平面上的极大点
//
//  Created by CYC on 10/27/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    
    int a[103] = {0}; //x坐标
    int b[103] = {0}; //y坐标
    int a1[103] = {0}; //符合要求的x坐标
    int b1[103] = {0}; //符合要求的y坐标
    int z = 0;        // 计数
        for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    
    
    for( int i = 0; i < n; i++){
        int num = 0;
        for( int j = 0; j < n; j++){
            if(a[i] > a[j] || b[i] > b[j]){
                num++;
                if(num == n - 1 ){
                    a1[z] = a[i];
                    b1[z] = b[i];
                    z++;
                }
            }
        }
    }
    
//    for( int i = 0; i < z; i++){
//        cout << a1[i] << b1[i] << endl;
//    }
    
    
    for( int i = 0; i < z - 1; i++){
        for( int j = 1 ; j < z - i; j++){
            if(a1[j - 1] > a1[j]){
                int temp1 = a1[j - 1];
                a1[j - 1] = a1[j];
                a1[j] = temp1;
                int temp2 = b1[j - 1];
                b1[j - 1] = b1[j];
                b1[j] = temp2;
            }
            if(a1[j - 1] == a1[j]){
                if(b1[j - 1] > b1[j]){
                    int temp3 = a1[j - 1];
                    a1[j - 1] = a1[j];
                    a1[j] = temp3;
                    int temp4 = b1[j - 1];
                    b1[j - 1] = b1[j];
                    b1[j] = temp4;
                }
            }
        }
    }
    
    for( int i = 0; i < z; i++){
        cout << "(" << a1[i] <<"," << b1[i] << ")" ;
        if( i != z - 1){
            cout << ",";
        }
    }
    
    cout << endl;
    
    return 0;
}
