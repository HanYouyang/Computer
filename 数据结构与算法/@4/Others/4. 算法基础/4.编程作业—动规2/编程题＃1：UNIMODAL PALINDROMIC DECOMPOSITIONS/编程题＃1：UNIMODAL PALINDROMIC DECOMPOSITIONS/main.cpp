//
//  main.cpp
//  编程题＃1：UNIMODAL PALINDROMIC DECOMPOSITIONS
//
//  Created by CYC on 1/14/16.
//  Copyright © 2016 CYC. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;

unsigned int num[256][256];

void number (unsigned int N){
    
    
    num[N][N] = 1;
    if( N % 2 == 0){
        num[N][N/2] = 1;
    }
    for( int i = N / 2; i > 0; i--){

        
            int j = N - 2*i;
            if( j >= i){
                if(num[j][j] == 0){
                    number(j);
                }
                int tem = 0;
                for( unsigned int z = j; z >= i; z--){
                    tem = tem + num[j][z];
                }
                num[N][i] = tem;
            }
        
            
        
    }
}




int main( ){
    int n;
    memset(num, 0, sizeof(num));
    
    num[1][1] = 1;
    num[2][1] = 1;
    num[2][2] = 1;

    while(cin >> n && n != 0){
        unsigned int total = 0;

        number(n);

        for( int i = n; i > 0; i--){
            total = total + num[n][i];
        }
        
        
        
        
        cout << n << " "<< total << endl;
        
//        for( int i = 1; i <= n ; i++){
//            cout << num[n][i] << " ";
//        }

    }
    
    
    
    

    
    
    
    
    
    
    
    return 0;
}
