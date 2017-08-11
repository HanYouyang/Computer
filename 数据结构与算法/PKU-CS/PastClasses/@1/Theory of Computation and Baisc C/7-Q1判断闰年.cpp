#include <iostream>
using namespace std;
//判断闰年
int main(){
    int year;
    cin >> year;

    if(year % 4 == 0){
        if(( year % 100 == 0 && year % 400 != 0 )|| year % 3200 == 0){
            cout << "N" << endl;
        }else{
            cout << "Y" << endl;
        }
    }else{
        cout << "N" << endl;
    }

    return 0;
}
