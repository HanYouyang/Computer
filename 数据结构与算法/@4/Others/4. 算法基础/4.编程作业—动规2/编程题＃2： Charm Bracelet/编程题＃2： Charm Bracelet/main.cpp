//
//  main.cpp
//  编程题＃2： Charm Bracelet
//
//  Created by CYC on 1/12/16.
//  Copyright © 2016 CYC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;


int main() {
    int N = 0;
    int M = 0;
    int w = 0;
    int d = 0;
    
    cin >> N >> M;
    
    int z[12882];
    memset(z,0,sizeof(z));
    //初始化z
    
    for( int i = 0 ; i < N; i++){
        cin >> w >> d;
        for( int j = M; j >= w; j--){
            z[j] = max(z[j - w] + d,z[j]);
        }
    }
    //
    int maxnum = 0;
    for( int i = 0; i <= M; i++){
        maxnum = max(maxnum,z[i]);
    }
    
    cout << maxnum << endl;
    
     
    return 0;
}
