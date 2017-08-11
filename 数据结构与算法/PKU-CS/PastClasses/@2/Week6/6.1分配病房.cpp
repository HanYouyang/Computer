//
//  main.cpp
//  编程题＃1：分配病房
//
//  Created by CYC on 10/7/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int m = 0;
    double max = 0;
    cin >> m >> max;
    
    int a[52] = {0};
    double b[52] = {0.00};
    int c[52] = {0};
    double d[52] = {0.00};
    
    int n = 0;
    for( int i = 0; i < m; i++){
        cin >> a[i] ;
        cin >> b[i] ;
        if(b[i] >= max){
            d[n] = b[i];
            c[n] = a[i];
            n++;
        }
    }
    
    if( n == 0){
        cout <<"None." << endl;
        return 0;
    }
    
    for( int i = 0; i < n - 1; i++){
        for( int j = 1; j < n ; j++){
            if( d[j-1] > d[j]){
                double temp1 = d[j-1];
                d[j-1] = d[j];
                d[j] = temp1;
                int temp2 = c[j-1];
                c[j-1] = c[j];
                c[j] = temp2;
            }
        }
    }
    
   
    
    for( int i = n - 1; i >= 0; i--){
        cout <<  setw(3) << setfill('0') << c[i] << " ";
        cout <<  fixed << setprecision(1) << d[i] << endl;
    }
    
    return 0;
}
