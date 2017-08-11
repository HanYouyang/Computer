//
//  main.cpp
//  编程题＃2：字符串中次数第2多的字母
//
//  Created by CYC on 10/26/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <string>


using namespace std;

int main() {
    string s;
    getline(cin,s);
//    cin >> s;
    
    for( int i = 0; i < s.length(); i++){
        s[i] = toupper(s[i]);
    }
    

    string c;
    c = s;
    int i = 0;
    while(i < c.length()) {
        if((c[i]<= 'Z' && c[i] >='A')  ){
            for( int j = 0; j < i; j++){
                if(c[i] == c[j]){
                    c.erase(i,1);
                    i--;
                }
            }
        }
        else{
            c.erase(i,1);
            i--;
        }
        i++;
    }
    
    int a = c.length();
    
//    cout << c << endl;
//    cout << a << endl;
    
    int num[28] = {0};
    
    for( int m = 0; m < s.length(); m++){
        for( int n = 0; n < c.length(); n++){
            if(s[m] == c[n]){
                num[n]++;
            }
        }
    }
    
//    for( int i = 0; i < c.length(); i++){
//        cout << num[i] << " ";
//    }
//    cout << endl;
    
    int max = 0;
    for( int i = 0; i < c.length();i++){
        if(num[i] > max){
            max = num[i];
        }
    }
    
    int secmax = 0;
    int index = 0;
    for( int i = 0 ; i < c.length(); i++){
        if(num[i] > secmax && num[i] < max){
            secmax = num[i];
            index = i;
        }
    }
    
    char g;
    g = c[index] + 32;
//    cout << g << endl;
    
    
    cout << c[index] << '+'<< g << ':' << num[index];
    
    return 0;
}




