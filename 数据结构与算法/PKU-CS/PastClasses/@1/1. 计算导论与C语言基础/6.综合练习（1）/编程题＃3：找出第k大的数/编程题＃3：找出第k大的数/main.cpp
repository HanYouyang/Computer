//
//  main.cpp
//  编程题＃3：找出第k大的数
//
//  Created by CYC on 7/30/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

void swap (int*_arry,int a, int b) {
    int temp = 0;
    temp = _arry[a];
    _arry[a] = _arry[b];
    _arry[b] = temp;
}

    
int main() {
    int N = 0;
    int K = 0;
    int a[1000];
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    for (int i = 0; i < K; i++){
        for (int j = 1; j < N -i; j++){
            if(a[j-1] > a[j]){
                swap(a, j-1, j);
            }
        }
            
    }
    cout << a[N-K]<< endl;
    
    
    return 0;
}