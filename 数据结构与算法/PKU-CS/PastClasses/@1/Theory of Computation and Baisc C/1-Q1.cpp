#include <iostream>
using namespace std;

int main(){
    int day;
    cin >> day;

    if(day == 1 || day == 3 || day == 5){
        cout << "NO" << endl;
    }else if(day == 2 || day == 4 || day == 6 || day == 7){
        cout << "YES" << endl;
    }else{
        cout << "Invalid Input" << endl;
    }

    return 0;
}
