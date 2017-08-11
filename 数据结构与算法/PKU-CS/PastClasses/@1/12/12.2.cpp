#include <iostream>
using namespace std;
int main(){
    int a[3] = { 3, 5, 7}, b[3] = {0};
    int n;
    while (cin >> n){
    for (int i = 0; i < 3; i++){
        if (n % a[i] == 0)
            b[i] = a[i];
        else
            b[i] = 0;
        }

    if (b[0] == 0 && b[1] == 0 && b[2] == 0 )
            cout << 'n' << ' ';
    else
        for (int j = 0; j < 3; j++){
            if (b[j] > 0 )
                cout << b[j] << ' ';
            }
    cout << endl;
  }
}
