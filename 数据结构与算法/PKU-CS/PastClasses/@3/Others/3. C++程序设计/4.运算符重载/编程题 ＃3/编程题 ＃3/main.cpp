//
//  main.cpp
//  编程题 ＃3
//
//  Created by CYC on 2/3/16.
//  Copyright © 2016 CYC. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码

class Array2 {
    int *p;
    int r, c;
public:
    Array2(){
        p = NULL;
    }
    Array2 (int r_, int c_): r(r_), c(c_){
        p = new int[r*c];
    }
    Array2  (Array2 &  a):r(a.r),c(a.c) {
        p = new int[r*c];
        memcpy(p, a.p, sizeof(int)* r*c);
    }
    Array2 & operator = (const Array2 &a){
        if (p == a.p) {
            return *this;
        }
        if(p){
            delete []p;
        }
        r = a.r;
        c = a.c;
        p = new int[r*c];
        memcpy(p,a.p, sizeof(int)*r*c);
        
        return *this;
    }
    int *  operator[](int i){
        return p + i*c;
    }
    int operator() (int i,int j){
        return p[i*c +j];
    }
    
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}