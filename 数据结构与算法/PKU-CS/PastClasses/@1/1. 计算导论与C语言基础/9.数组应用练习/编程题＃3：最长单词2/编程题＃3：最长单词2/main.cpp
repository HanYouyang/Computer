//
//  main.cpp
//  编程题＃3：最长单词2
//
//  Created by CYC on 8/7/15.
//  Copyright © 2015 CYC. All rights reserved.
//
//
#include <iostream>
using namespace std;

int main() {
    char s[500];
    cin.getline(s,499);
    
    int maxnum = 0;
    int maxend = 0;
    int num = 0;
    int end = 0;
    for (int i = 0; i < 500; i++){
        
        if(s[i]!= '\0'&& s[i]!='.'&& s[i]!=' '){
            num++;
            end = i;
            if( num > maxnum){
                maxnum = num;
                maxend = end;
            }
        }
        
        if(s[i]==' '){
            num = 0;
        }
        if(s[i]== '\0'|| s[i]=='.')
            break;
    }
    
    for( int i = maxend - maxnum +1; i <= maxend; i++){
        cout << s[i];
    }
    
    cout << endl;
    
    
    
    return  0;
}
