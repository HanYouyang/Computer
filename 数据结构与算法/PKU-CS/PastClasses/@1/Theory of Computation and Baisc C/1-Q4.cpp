#include <iostream>
using namespace std;

int main(){
    int nSize, division, remainder;

    cin >> nSize;
    int number[nSize], times[nSize];

    for(int i = 0; i < nSize; i++){
        cin >> number[i];
    }

    for(int i = 0; i < nSize; i++){
        division = 1;
        times[i] = 0;
        while(division != 0){
            division = number[i] / 2;
            remainder = number[i] % 2;
            if(remainder == 1){
                times[i] += 1;
            }
            number[i] = division;
        }

    }

    for(int i = 0; i < nSize; i++){
        cout << times[i] << endl;
    }

    return 0;
}