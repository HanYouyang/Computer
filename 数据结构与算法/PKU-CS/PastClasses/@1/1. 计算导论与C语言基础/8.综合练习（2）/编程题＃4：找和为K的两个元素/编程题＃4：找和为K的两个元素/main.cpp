//
//  main.cpp
//  编程题＃4：找和为K的两个元素
//
//  Created by CYC on 8/1/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;
//
//void jiancha(int* _a, int _n, int _k){
//    int sum = 0;
//    for (int i = 0; i < _n; i++){
//        for ( int j = i; j < _n; j++){
//            sum = _a[i] + _a[j];
//            if (sum == _k){
//                cout << "yes" << endl;
//                return;
//            }
//        }
//    }
//    cout << "no" << endl;
//}

int main() {
    int n = 0;
    int k = 0;
    int a[1001];
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            sum = a[i] + a[j];
            if ( sum == k){
                cout << "yes"<< endl;
                break;
            }
            
                
        }
        if ( sum == k){
            break;
        }
    }
    
    if (sum != k){
    cout << "no" <<endl;
    }
    
    
    return  0;
}