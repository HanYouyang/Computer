//
//  main.cpp
//  编程题＃1：年龄与疾病
//
//  Created by CYC on 7/29/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n = 0;
    int a[1000];
    cin >> n;
    for ( int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int num1 = 0;
    double precent1 = 0.00;
    for ( int i = 0; i < n; i++) {
        if ( (a[i] > 0) && (a[i]<= 18)) {
            num1 = num1 + 1;
        }
        else {
            num1 = num1;
        }
    }
    precent1 =( double(num1) / double (n)) * 100.00;
    
    int num2 = 0;
    double precent2 = 0.00;
    for ( int i = 0; i < n; i++) {
        if ( (a[i] > 18) && (a[i]<= 35)) {
            num2 = num2 + 1;
        }
        else {
            num2 = num2;
        }
    }
    precent2 =( double(num2) / double (n)) * 100.00;

    int num3 = 0;
    double precent3 = 0.00;
    for ( int i = 0; i < n; i++) {
        if ( (a[i] > 35) && (a[i]<= 60)) {
            num3 = num3 + 1;
        }
        else {
            num3 = num3;
        }
    }
    precent3 =( double(num3) / double (n)) * 100.00;
    
    int num4 = 0;
    double precent4 = 0.00;
    for ( int i = 0; i < n; i++) {
        if ( (a[i] > 60) && (a[i]<= 1000)) {
            num4 = num4 + 1;
        }
        else {
            num4 = num4;
        }
    }
    precent4 =( double(num4) / double (n)) * 100.00;


    
    
    
    
    

    cout <<"1-18: " << fixed << setprecision(2) << precent1  << '%' << endl<<"19-35: " << fixed << setprecision(2) << precent2  << '%' << endl<<"36-60: " << fixed << setprecision(2) << precent3  << '%' << endl <<"60-: " << fixed << setprecision(2) << precent4  << '%' << endl;
    
    
    
    
    return  0;

}