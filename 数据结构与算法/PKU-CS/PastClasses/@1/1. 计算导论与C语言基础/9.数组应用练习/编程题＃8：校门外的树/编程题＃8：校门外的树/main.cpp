//
//  main.cpp
//  编程题＃8：校门外的树
//
//  Created by CYC on 8/8/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int L = 0;
    int M = 0;
    cin >> L >> M;
    
    
    int move[10001]= {};
    for( int i = 0; i < M; i++){
        int begin = 0;
        int end = 0;
        cin >> begin >> end;
        for( int j = begin; j <= end; j++){
            move[j] = 1;
        }
        
    }
    
    int num = 0;
    for( int i = 0; i <= L; i++){
        if( move[i] == 0){
            num++;
        }
    }
    
    cout << num << endl;
    
    
    
    
    return 0;
}