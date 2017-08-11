#include <iostream>
using namespace std;

int main(){
    int apple, apple_left, rate, time;

    cin >> apple;
    cin >> rate;
    cin >> time;

    if(time % rate == 0){
        if(time / rate >= apple){
            apple_left = 0;
        }else{
            apple_left = apple - time / rate;
        }
    }else{
        if(time / rate >= apple){
            apple_left = 0;
        }else{
            apple_left = apple - 1 - time / rate;
        }
    }

    cout << apple_left << endl;

    return 0;
}
