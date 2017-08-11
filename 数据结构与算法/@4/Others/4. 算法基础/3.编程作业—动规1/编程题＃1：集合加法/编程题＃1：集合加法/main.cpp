//
//  main.cpp
//  编程题＃1：集合加法
//
//  Created by CYC on 12/30/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int a = 0;
    int b = 0;
    int s = 0;
    int A[10002];
    int B[10002];
    
    cin >> n;
    for( int i = 0; i < n; i++){
        cin >> s;
        cin >> a;
        for( int i = 0; i < a; i++){
            cin >> A[i];
        }
        cin >> b;
        for( int j = 0; j < b; j++){
            cin >> B[j];
        }
        int num = 0;
        int tem = 0;
        for( int i = 0; i < a; i++){
            tem = s - A[i];
            for( int j = 0; j < b; j++){
                if(B[j] == tem){
                    num++;
                }
            }
        }
        
        cout << num << endl;
        
    }
    
    return 0;
}
