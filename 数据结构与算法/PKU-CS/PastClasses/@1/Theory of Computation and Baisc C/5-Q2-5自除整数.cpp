#include <iostream>
using namespace std;
//自整除数
int main(){   
    int maxNum;
    cin >> maxNum;

    for(int i = 10; i < maxNum + 1; i++){
        if( i % (i/10+i%10) == 0 ){
            cout << i << endl;
        }
    }

    return 0;
}
