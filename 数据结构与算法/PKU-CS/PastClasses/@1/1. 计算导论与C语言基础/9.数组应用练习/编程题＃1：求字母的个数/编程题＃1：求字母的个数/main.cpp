//
//  main.cpp
//  编程题＃1：求字母的个数
//
//  Created by CYC on 8/3/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[80];
    cin.get(s,80);
    int A = 0;
    int E = 0;
    int I = 0;
    int O = 0;
    int U = 0;
    
    for (int i = 0; i < 80; i++) {
        switch (s[i]) {
            case 'a':
                A++;
                break;
            case 'e':
                E++;
                break;
            case 'i':
                I++;
                break;
            case 'o':
                O++;
                break;
            case 'u':
                U++;
                break;
                
            default:
                break;
        }
        
        
    }
    
    cout << A <<" "<< E <<" "<< I <<" "<< O <<" "<< U <<endl;
    
    
    
    
    
    
    return 0;
}