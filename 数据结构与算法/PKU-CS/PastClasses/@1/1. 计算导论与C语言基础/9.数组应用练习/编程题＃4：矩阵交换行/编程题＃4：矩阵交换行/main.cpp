//
//  main.cpp
//  编程题＃4：矩阵交换行
//
//  Created by CYC on 8/7/15.
//  Copyright © 2015 CYC. All rights reserved.
//
//



#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a[5][5];
    for ( int i = 0; i < 5; i++)
        for( int j = 0; j < 5; j++)
            cin >> a[i][j];
    
    int n ,m ;
    cin >> n >> m;
    
    if (n < 0 || n >= 5 || m < 0 || m >= 5 ){
        cout << "error" << endl;
        return 0;
    }
            
    for(int i = 0; i < 5; i++){
        int tem = i;
        if(tem == n)
            tem = m;
        else if(tem == m)
            tem = n;
        for (int j = 0; j < 5; j++)
            cout << setw(4) << a[tem][j];
        cout << endl;
    }
    
    return 0;
}


