#include <iostream>
using namespace std;
int main() {
    int N;
    char C;
    cin >> N >> C;
    int height;
    if (N % 2 == 0) {
        height = N / 2;
    } else {
        height = N / 2 + 1;
    }
    for(int i = 0; i < N; i++)
        cout << C;
    cout << endl;
    for (int i = 0; i < height - 2; i++) {
        cout << C;
        for (int k = 0; k < N - 2; k++)
            cout << " ";
        cout << C << endl;
    }
    for (int i = 0; i < N; i++)
        cout << C;
    return 0;
}
