#include <iostream>
using namespace std;
//在一个长度为n(n < 1000)的整数序列中，判断是否存在某两个元素之和为k。
int main(){   
    int length, sumReq;
    bool flag = false;
    cin >> length;
    cin >> sumReq;
    int number[length];

    for(int i = 0; i < length; i++){
        cin >> number[i];
    }

    for(int i = 0; i < length-1; i++){
        for(int j = 1; j < length - i; j++){
            if(number[i] + number[j] == sumReq){
                flag = true;
            }

        }
    }

    if(flag == true)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
