#include <iostream>

using namespace std;
//用户输入N和K，然后接着输入N个正整数（无序的），程序在不对N个整数排序的情况下
//找出第K大的数。注意，第K大的数意味着从大到小排在第K位的数。
int main(){
    int nSize, maxK;

    cin >> nSize;
    int number[nSize];
    cin >> maxK;

    for(int i = 0; i < nSize; i++){
        cin >> number[i];
    }

    for(int i =0; i < nSize -1; i++){
        for(int j = 1; j< nSize - i; j++){
            if(number[j-1] < number[j]){
                int temp = number[j];
                number[j] = number[j-1];
                number[j-1] = temp;
            }
        }
    }

    cout << number[maxK-1] << endl;

    return 0;
}