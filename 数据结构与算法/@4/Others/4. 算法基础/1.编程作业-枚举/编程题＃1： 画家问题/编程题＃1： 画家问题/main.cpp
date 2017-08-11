//
//  main.cpp
//  编程题＃1： 画家问题
//
//  Created by CYC on 11/22/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include<cmath>
#include<memory.h>
using namespace std;
int n;
int map[18][18] ;
int  press[18][18] ;

void  init()
{
    cin >> n;
    memset(map,0,sizeof(map));
    memset(press,0,sizeof(press));
    char a[18][18];
    for( int i = 1; i < n + 1; i++){
        for( int j = 1; j < n +1; j++){
            cin >> a[i][j];
        }
    }
    for( int i = 1; i < n + 1; i++){
        for( int j = 1; j < n + 1; j++){
            if(a[i][j] == 'w'){
                map[i][j] = 1;
            }
            if(a[i][j] == 'y'){
                map[i][j] = 0;
            }
        }
    }
}

bool check(){
    for(int i = 1; i < n + 1 ; i++){
        for(int j = 1; j < n + 1; j++){
            press[i + 1][j] =( map[i][j] + press[i][j] + press[i-1][j] + press[i][j-1] + press[i][j+1]) %2;
        }
    }
    
    int endtotal = 0;
    for( int k = 1; k < n + 1; k++){
        endtotal = endtotal + press[n + 1][k];
    }
    if(endtotal == 0){
        return 1;
    }
    
    return 0;
}


//第一行的状态
int enumerate(){
    for( int z = 0; z < pow(2,n); z++){
        if(check() == 0){
            press[1][1]++;
            for( int i = 1; i < n + 1; i++){
                if(press[1][i] > 1){
                    press[1][i] = 0;
                    press[1][i+1]++;
                }
                
            }
        }
        else{
            return 1;
        }
        
    }
    return -1;
}



int main(){
    int t = 0;
    cin >> t;
    for (int o = 0; o < t; o++ ) {
        init();
        if(enumerate() == 1){
            int max = 0;
            for( int i = 1; i < n + 1; i++){
                for( int j = 1; j < n +1 ; j++){
                    max = max + press[i][j];
                }
            }
            cout << max << endl;
        }
        else{
            cout <<"inf"<<endl;
        }
        
    }
    
    
    
    
    
    return 0;
}



