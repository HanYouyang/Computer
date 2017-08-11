#include <iostream>
using namespace std;

int main(){
    int diff, number[6], max_odd = 0, min_even = 100;

    for(int i = 0; i < 6; i++){
        cin >> number[i];
    }

    for(int i = 0; i < 6; i++){
        if(number[i] % 2 == 0){
            //even number
            if(number[i] <= min_even){
                min_even = number[i];
            }
        }else{
            //odd number
            if(number[i] >= max_odd){
                max_odd = number[i];
            }
        }
    }

    diff = max_odd - min_even;
    if(diff < 0){
        diff = diff * (-1);
    }

    cout << diff << endl;

    return 0;
}
