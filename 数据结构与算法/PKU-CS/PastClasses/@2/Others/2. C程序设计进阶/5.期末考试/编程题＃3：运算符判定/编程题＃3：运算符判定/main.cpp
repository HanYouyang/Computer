//
//  main.cpp
//  编程题＃3：运算符判定
//
//  Created by CYC on 10/26/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    
    
    int a[4] = {0};
    int anum = 0;
    int begin = 0;
    for( int i = 0; i <= s.length(); i++){
        if( s[i] == ',' || s[i] == '\0' ){
            int sum = 0;
            int num = i - begin - 1;
            for( int j = begin; j < i; j++){
//                cout << "num:" << num << " ";
//                cout << "每一次sum:"<< sum<< " ";
                sum = sum + (s[j]-'0')*pow(10,num);
//                cout << "算出来的sum："<< sum<< " ";
                 num = num - 1;
            }
            a[anum] = sum;
            anum++;
            begin = i + 1;
        }
    }
    
//    for ( int i = 0; i < 3; i++){
//        cout << a[i] << endl;
//    }

    
    if( a[0] + a[1] == a[2]){
        cout << "+" << endl;
    }
    else if( a[0] - a[1] == a[2]){
        cout << "-" << endl;
    }
    else if( a[0] * a[1] == a[2]){
        cout << "*" << endl;
    }
    else if( a[0] / a[1] == a[2]){
        cout << "/" << endl;
    }
    else if( a[0] % a[1] == a[2]){
        cout << "%" << endl;
    }
    else if(a[0] + a[1] != a[2] && a[0] - a[1] != a[2] && a[0] * a[1] != a[2] && a[0] / a[1] != a[2] && a[0] % a[1] != a[2]){
        cout << "error"<< endl;
    }
   
    
    
    
    
    
    
    
    
    
    
    return 0;
}
