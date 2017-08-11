//
//  main.cpp
//  编程题＃2：忽略大小写比较字符串大小
//
//  Created by CYC on 8/3/15.
//  Copyright © 2015 CYC. All rights reserved.
//
//
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char s[80];
    char m[80];
    cin >> s >> m;
    
    for( int i = 0; i < sizeof(s); i++){
        s[i] = toupper(s[i]);
    }
    for( int i = 0; i < sizeof(m); i++){
        m[i] = toupper(m[i]);
    }

    
    int r;
    r = strcmp(s, m);
    
    if (r == 0){
        cout << '=' << endl;
    }
    if (r < 0) {
        cout << '<' << endl;
    }
    if (r > 0) {
        cout << '>' << endl;
    }
    
 
    
    return 0;
}
