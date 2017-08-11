//
//  main.cpp
//  编程题＃2：拨钟问题
//
//  Created by CYC on 11/28/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;


int main() {
    int b[11] = {0};
    for( int i = 0; i < 9; i++){
        cin >> b[i];
    }
    int init[11]={0};
    memcpy(init,b,sizeof(b));
    
    
    int num[11]={0};
    int min = 262144;
    
    
    for(int a1 = 0; a1 < 4; a1++){
        for(int a2 = 0; a2 < 4; a2++){
            for(int a3 = 0; a3 < 4; a3++){
                for(int a4 = 0; a4 < 4; a4++){
                    for(int a5 = 0; a5 < 4; a5++){
                        for(int a6 = 0; a6 < 4; a6++){
                            for(int a7 = 0; a7 < 4; a7++){
                                for(int a8 = 0; a8 < 4; a8++){
                                    for(int a9 = 0; a9 < 4; a9++){
                                        memcpy(b,init,sizeof(init));
                                        
                                        //1
                                        b[0] = b[0] + a1;
                                        b[1] = b[1] + a1;
                                        b[3] = b[3] + a1;
                                        b[4] = b[4] + a1;
                                        //2
                                        b[0] = b[0] + a2;
                                        b[1] = b[1] + a2;
                                        b[2] = b[2] + a2;
                                        //3
                                        b[1] = b[1] + a3;
                                        b[2] = b[2] + a3;
                                        b[4] = b[4] + a3;
                                        b[5] = b[5] + a3;
                                        //4
                                        b[0] = b[0] + a4;
                                        b[3] = b[3] + a4;
                                        b[6] = b[6] + a4;
                                        //5
                                        b[1] = b[1] + a5;
                                        b[3] = b[3] + a5;
                                        b[4] = b[4] + a5;
                                        b[5] = b[5] + a5;
                                        b[7] = b[7] + a5;
                                        //6
                                        b[2] = b[2] + a6;
                                        b[5] = b[5] + a6;
                                        b[8] = b[8] + a6;
                                        //7
                                        b[3] = b[3] + a7;
                                        b[4] = b[4] + a7;
                                        b[6] = b[6] + a7;
                                        b[7] = b[7] + a7;
                                        //8
                                        b[6] = b[6] + a8;
                                        b[7] = b[7] + a8;
                                        b[8] = b[8] + a8;
                                        //9
                                        b[4] = b[4] + a9;
                                        b[5] = b[5] + a9;
                                        b[7] = b[7] + a9;
                                        b[8] = b[8] + a9;
                                        
                                        
                                        for( int j = 0; j < 9; j++){
                                            if(b[j] > 3){
                                                b[j] = b[j] % 4;
                                            }
                                        }
                                        
                                        int zero = 0;
                                        for( int i = 0; i < 9; i++){
                                            zero = zero + b[i];
                                        }
                                        
                                        if(zero == 0){
                                            int total = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9;
                                            if(total < min){
                                                min = total;
                                                num[0] = a1;
                                                num[1] = a2;
                                                num[2] = a3;
                                                num[3] = a4;
                                                num[4] = a5;
                                                num[5] = a6;
                                                num[6] = a7;
                                                num[7] = a8;
                                                num[8] = a9;
                                                
                                                
                                                
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    for( int i = 0; i < 9;i++){
        if(num[i] != 0){
            for(int j = 0; j <num[i];j++){
                cout << i + 1 << ' ';
            }
        }
    }
    
    
    return 0;
}
