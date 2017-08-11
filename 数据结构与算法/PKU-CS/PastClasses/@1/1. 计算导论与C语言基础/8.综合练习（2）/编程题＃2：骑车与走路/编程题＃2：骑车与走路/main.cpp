//
//  main.cpp
//  编程题＃2：骑车与走路
//
//  Created by CYC on 7/31/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int s[1000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    
    for (int i = 0; i < n; i++){
        double timebike = 0;
        double timewalk = 0;
        timebike = (50 + double(s[i])/3);
        timewalk = (double(s[i])/1.2);
        if ( timewalk > timebike){
            cout << "Bike" << endl;
        }
        if ( timewalk < timebike) {
            cout << "Walk" << endl;
        }
        if ( timebike == timewalk) {
            cout <<  "All" << endl ;
        }

    }
    
    
    
    
    return  0;
}