#include <iostream>
using namespace std;

int main(){
    int number, digits, tens, hundreds;

    cin >> number;

    hundreds = number / 100;
    tens = (number - 100 * hundreds) / 10;
    digits = number - 100 * hundreds - 10 * tens;

    cout << hundreds << endl;
    cout << tens << endl;
    cout << digits <<endl;

    return 0;
}
