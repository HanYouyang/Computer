//
//  main.cpp
//  编程题＃5：字符串插入
//
//  Created by CYC on 8/10/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main (){
    
    char string[11]; char substr[4];
    while ( cin >> string){
        cin >> substr;
        
        int max = 0;
        int maxwz = 0; //max的位置
        for (int i = 0; i < 10; i++) {
            if (string[i] == '\0') {
                break;
            }
            if(string[i] > max) {
                max = string[i];
                maxwz = i;
                
            }
        }
        
        for( int i = 0; i <=maxwz; i++){
            cout << string[i];
        }
        cout << substr;
        for ( int j = maxwz+1; j < 10; j++){
            if (string[j] == '\0') {
                break;
            }
            cout << string[j];
        }
        
        
        cout << endl;
        
        
    
    
    }
    
return 0;
}
