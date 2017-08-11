#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
//含k个3的数
int NumberOfThree(int number){
    int Three = 0;
    char number_ch[100];
    sprintf(number_ch, "%d", number);
    for(int i = 0; number_ch[i] != '\0'; i++){
        if(number_ch[i] == '3'){
            Three++;
        }
    }
    return Three;
}

int main(){ 
    int m, k;
    cin >> m >> k;

    if(m % 19 == 0){
        if(NumberOfThree(m) == k){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
