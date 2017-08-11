//
//  main.cpp
//  编程题＃7：中位数
//
//  Created by CYC on 8/7/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main () {
    int N = 0;
    int a[15000];
    while (cin >> N){
        if( N ==0){
            break;
            
        }
    
        for (int i = 0; i < N; i++){
            cin >>a[i];
        }
    
        for( int i = 0; i < N -1 ; i++){
            for (int j = 0; j < N -1 -i; j++){
                int tem = 0;
                if( a[j] < a[j+1]){
                    tem = a[j];
                    a[j]= a[j+1];
                    a[j+1]=tem;
                }
            }
        }
        int midnum = 0;
        if (N % 2 != 0){
            midnum = a[N/2];
        }
        else if(N % 2 == 0){
            midnum = (a[N/2-1]+ a[N/2])/2;
        }
        
        
        cout << midnum << endl;

        
    }
    

    
        return 0;
}