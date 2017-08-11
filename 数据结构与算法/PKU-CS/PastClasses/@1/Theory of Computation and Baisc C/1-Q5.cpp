#include <iostream>
using namespace std;

int main(){
    int nSize;

    cin >> nSize;
    int number[nSize], number_dealed[nSize] ;

    for(int i = 0; i < nSize; i++){
        cin >> number[i];
    }

    for(int i = 0; i < nSize; i++){
        number_dealed[nSize-i-1] = number[i];
    }

    for(int i = 0; i < nSize; i++){
        cout << number_dealed[i] << " ";
    }

    return 0;
}