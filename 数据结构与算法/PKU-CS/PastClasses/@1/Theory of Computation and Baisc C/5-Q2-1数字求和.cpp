#include <iostream>

using namespace std;
//数字求和,给定一个正整数a，以及另外的5个正整数，问题是：这5个整数中，小于a的整数的和是多少？
int main(){
    int number[6], numberSmaller[5], nSize = 0, sum = 0;

    for(int i = 0; i < 6; i++){
        cin >> number[i];
    }

    for(int i = 1; i < 6; i++){
        if(number[i] < number[0]){
            numberSmaller[nSize] = number[i];
            nSize += 1;
        }
    }

    for(int i = 0; i < nSize; i++){
        sum += numberSmaller[i];
    }

    cout << sum << endl;

    return 0;
}