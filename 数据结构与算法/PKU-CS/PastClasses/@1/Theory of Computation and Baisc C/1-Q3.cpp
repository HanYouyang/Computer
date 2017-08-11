#include <iostream>
using namespace std;

int main(){
    int nSize, number[99];
    int times_one = 0, times_five = 0, times_ten = 0;
	
    cin >> nSize;
	
    if(nSize > 1 && nSize < 100){
        for(int i = 0; i < nSize; i++){
            cin >> number[i];
        }
        for(int i = 0; i < nSize; i++){
            if(number[i] == 1){
                times_one += 1;
            }else if(number[i] == 5){
                times_five += 1;
            }else if(number[i] == 10){
                times_ten += 1;
            }
        }
        cout << times_one << endl;
        cout << times_five << endl;
        cout << times_ten << endl;
    }else{
        cout << "Invalid Input" << endl;
    }

    return 0;
}
