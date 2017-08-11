//
//  main.cpp
//  编程题＃3：最远距离
//
//  Created by CYC on 8/9/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;


double pf (double a){
    return a*a;
}


int main() {
    int n = 0;
    cin >> n;
    
    double a[1000][2];
    for ( int i = 0; i < n; i++){
        for( int j = 0; j < 2; j++){
            cin >> a[i][j];
        }
    }
    
    
    
    double maxdis = 0.0000;
    for ( int i = 0; i < n; i++){
        for( int j = 0; j < n; j++){
            double dis = 0.0000;
            dis = sqrt(pf(a[i][0]-a[j][0])+pf(a[i][1]-a[j][1]));
            if(dis > maxdis){
                maxdis = dis;
            }
        }
    }
    
    cout << maxdis << endl;
    
    
    return  0;
}