//
//  main.cpp
//  编程题＃4：魔兽世界之一：备战
//
//  Created by CYC on 1/26/16.
//  Copyright © 2016 CYC. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int totaltime;
int minenergy;




class base{
    int energy;
    int monsblood[5];
    string basename;
    int order[5];
    int totalmons[5];
    
    
public:
    int count;
    int end;
    static string monsname[5];
    base(int n,int a[5],int b[5],string s){
        energy = n;
        for( int i = 0;i < 5; i++){
            monsblood[i] = a[i];
        }
        for( int j = 0;j < 5; j++){
            order[j] = b[j];
        }
        basename = s;
        for( int z = 0; z <5; z++){
            totalmons[z] = 0;
        }
        count = 0;
        end = 1;
    }
    void process();
    void countchange(int a);
};
string base::monsname[5] = {"dragon","ninja","iceman","lion","wolf"};

void base:: countchange (int a){
    if(a > 4){
        a = a - 5;
    }
}

void base:: process(){
    if(end == 0){
        return;
    }
    else{
        if(energy < minenergy){
            cout << setw(3) << setfill('0')<< totaltime <<" " <<basename << " headquarter stops making warriors" << endl;
            end = 0;
            return;
        }
        //下面的代码需要优化
        if(energy < monsblood[order[count]]){
            count++;
            if(count > 4){
                count = count - 5;
            }
            for( int i = 0; i < 3; i++){
                if(energy >= monsblood[order[count]]){
                    i = 3;
                }
                else{
                    count++;
                    if(count > 4){
                        count = count - 5;
                    }
                }
            }
        }
    
        energy = energy - monsblood[order[count]];
        totalmons[order[count]]++;
        cout << setw(3) << setfill('0')<< totaltime <<" "<< basename <<" " <<monsname[order[count]] <<" " << totaltime + 1 << " born with strength "<< monsblood[order[count]] << "," << totalmons[order[count]] << " " << monsname[order[count]] <<" in " << basename << " headquarter" << endl;
    
    
        count++;
        if(count > 4){
            count = count - 5;
        }
            return;
        }
    
}










int main( ) {
    int team = 0;
    int a = 1;
    cin >> team;
    for( int i = 0; i < team; i++){
        cout << "Case:"<< a <<endl;
        a++;
        //每一组数据开始
        totaltime = 0;
        minenergy = 20000;
        int n = 0; //energy
        int a[5] = {0};
        int bred[5] = {2,3,4,1,0};
        int bbule[5] = {3,0,1,2,4};
        cin >> n;
        for( int i = 0; i < 5; i++){
            cin >> a[i];
            if(minenergy > a[i]){
                minenergy = a[i];
            }
        }
        
        base red(n,a,bred,"red");
        base blue(n,a,bbule,"blue");
        
        for( int i = 0; i < 10000; i++){
            if(red.end + blue.end == 0){
                break;
            }
            else{
                red.process();
                blue.process();
               
                
                totaltime ++;

                
            }
        }
        
        
        
        
        
        
        
    }
    return 0;
}








