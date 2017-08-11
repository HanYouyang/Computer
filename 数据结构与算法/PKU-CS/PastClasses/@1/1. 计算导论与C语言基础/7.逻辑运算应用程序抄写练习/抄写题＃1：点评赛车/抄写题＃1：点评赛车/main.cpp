//
//  main.cpp
//  抄写题＃1：点评赛车
//
//  Created by CYC on 8/1/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int best;


int main() {
    for (int best = 0; best <= 4; best++) {
    bool a = (best == 2);
    bool b = (best == 4);
    bool c = (best != 3);
    bool d = !b;
        if (a + b + c + d != 1){
            continue;
        }
            cout << best << endl;
        
        if ( a == 1){
            cout << "A" << endl;
        }
        if ( b == 1){
            cout << "B" << endl;
        }
        if ( c == 1){
            cout << "C" << endl;
        }
        if ( d == 1){
            cout << "D" << endl;
        }
    
    }
    
    
    
    
    
    
    return  0;
}