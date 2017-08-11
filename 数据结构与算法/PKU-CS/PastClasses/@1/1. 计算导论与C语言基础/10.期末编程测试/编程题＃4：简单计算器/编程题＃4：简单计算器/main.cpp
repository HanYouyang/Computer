//
//  main.cpp
//  编程题＃4：简单计算器
//
//  Created by CYC on 8/10/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = 0;
    char c;
    cin >> a >> b >> c;
    
    
    if(c == '+'){
        cout << a + b << endl;
    }
    else if(c == '-'){
       cout << a - b << endl;
    }
    else if(c == '*'){
        cout << a * b << endl;
    }
    else if(c == '/'){
        if( b != 0){
            cout << a / b << endl;
        }
        else if ( b == 0){
            cout << "Divided by zero!" << endl;
        }
    }
    else{
        cout << "Invalid operator!" << endl;
    }
    

    
    
    
    
    
    
return 0;
}
