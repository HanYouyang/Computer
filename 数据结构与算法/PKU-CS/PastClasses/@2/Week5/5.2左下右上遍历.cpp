//
//  main.cpp
//  编程题＃2: 二维数组右上左下遍历
//
//  Created by CYC on 10/7/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    int row = 0;
    int col = 0;
    cin >> row >> col;
    int a[102][102] = {0};
    for( int i = 0; i < row; i++){
        for( int j = 0; j < col; j++){
            cin >> a[i][j];
        }
    }
    

    
    for( int k = 0; k <= row + col - 2; k++){
        for(int j = col - 1; j >= 0; j--){
            for( int i = 0; i <= row - 1; i++){
                if(i + j == k){
                    cout << a[i][j] << endl;
                }
            }
        }
    }
    
    
    
    
    
    
    return 0;
}
