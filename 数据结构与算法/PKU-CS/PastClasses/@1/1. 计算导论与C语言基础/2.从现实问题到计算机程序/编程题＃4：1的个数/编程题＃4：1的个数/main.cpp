//
//  main.cpp
//  编程题＃4：1的个数
//
//  Created by CYC on 7/24/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int N = 0; int a[10000];
    cin >> N;
    for (int i = 0 ; i < N; i++){
        cin >> a[i];
    }
    
    
    for ( int j = 0; j < N; j++){
        int num = 0;
        for ( int k = 0; k < 10000; k++){
            if ((a[j] >= 1) && (a[j] % 2 ==1)){
                a[j] = int ( a[j] / 2);
                num = num + 1;
            }
            if((a[j] >= 1) && (a[j] % 2 !=1)){
                a[j] = int ( a[j] / 2);
                num = num;
            }
            if(a[j] < 1){
                break;
            }
            
        }
        cout << num << endl;
    }
    
    

    
    return 0;
}


