//
//  main.cpp
//  编程题＃5：异常细胞检测
//
//  Created by CYC on 8/7/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N =0;
    cin >> N;
    
    int a[101][101];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
    
    int num = 0;
    for (int i = 1; i < N -1; i++ )
        for(int j = 1; j < N - 1; j++)
            if(a[i-1][j] - a[i][j] >= 50 &&
               a[i][j-1] - a[i][j] >= 50 &&
               a[i][j+1] - a[i][j] >= 50 &&
               a[i+1][j] - a[i][j] >= 50)
                num ++;
               
    
    
    cout << num << endl;
    
    
    return  0;
}