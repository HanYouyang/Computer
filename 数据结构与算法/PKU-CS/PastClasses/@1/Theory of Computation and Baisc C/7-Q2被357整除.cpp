#include <iostream>
using namespace std;
//能被3，5，7整除的数
int main(){
    int n;

    while(cin>>n){
        if( n % 3 == 0 || n % 5 == 0 || n % 7 == 0){
            if( n % 3 == 0){
                cout << "3 ";
            }
            if( n % 5 == 0){
                cout << "5 ";
            }
            if( n % 7 == 0){
                cout << "7";
            }
            cout << "\n";
        }else{
            cout << "n" << endl;
        }
    }

    return 0;
}
