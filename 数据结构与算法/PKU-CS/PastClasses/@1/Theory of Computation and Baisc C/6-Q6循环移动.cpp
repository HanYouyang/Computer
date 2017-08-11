#include <iostream>
using namespace std;
//循环移动
int main(){

    int n, m;
    cin >> n >> m;
    int number[n], store[m];

    for(int i = 0; i < n; i++){
        cin >> number[i];
    }

    int counter = 0;
    for(int i = n - m; i < n; i++){
        store[counter] = number[i];
        counter += 1;
    }

    for(int i = n-1; i > m-1; i--){
        number[i] = number[i-m];
    }

    counter = 0;
    for(int i = 0; i < m; i++){
        number[i] = store[counter];
        counter += 1;
    }

    for(int i = 0; i < n; i++){
        cout << number[i] << " ";
    }

    return 0;
}