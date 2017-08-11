#include <iostream>
using namespace std;

int main() {
    int N = 0;
    cin >> N;
    int a[1000];
    for ( int i = 0; i < N; i++){
        cin >> a[i];
    }
    for ( int j = 0; j < N; j++){
        if( a[j] == j){
            cout << a[j] << endl;
            break;
        }
        if((j == N-1) && (a[j] != j)){
            cout << "N";
        }
    }
    return 0;
}