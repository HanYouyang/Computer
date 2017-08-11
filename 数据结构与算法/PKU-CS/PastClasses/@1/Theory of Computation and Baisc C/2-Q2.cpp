#include <iostream>
#define PI 3.14159
using namespace std;

int main(){
    int radius, height, amount;
    float volume;
    cin >> height;
    cin >> radius;

    volume = PI * radius * radius * height;

    amount = int(20000 / volume);

    if(20000 / volume - amount > 0){
        amount = amount + 1;
    }

    cout << amount << endl;

    return 0;
}

