//
//  main.cpp
//  编程题＃3：买房子
//
//  Created by CYC on 8/1/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int N = 0;
    double K = 0;
    
    while(cin >> N >> K){
    
    int M = 0;
    while (((200 * pow(K/100+1, double(M-1))) > (N * M)) && (M < 21) ){
        M++;
    }
    if ( M < 21){
        cout << M << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
    }
    
    
    
    
    
//    int M = 0;
//    for (M = 1; M < 21; M++) {
////        cout << 200*pow(K/100+1, double(M)) << " " << N*(M+1) << endl;
//        if( ((200 * pow(K/100+1, double(M-1))) <= (N * M))  ){
//            cout << M << endl;
//            break;
////
//    }
//    if ( M > 20 ){
//        cout << "impossible"  << endl;
//    }
//    
    
    
    
    return 0;
}
