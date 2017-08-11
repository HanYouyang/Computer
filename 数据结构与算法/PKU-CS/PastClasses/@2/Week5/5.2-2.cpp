#include <iostream>
using namespace std;

int main() {
    int row = 0, rol = 0;
    cin >> row >> rol;
    int array[100][100] = {0};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < rol; j++) {
            cin >> array[i][j];
        }
    }

    int x = 0, y = 0;
    for (int i = 0; i < row + rol - 1; i++) {
        x = i > rol - 1 ? i - rol + 1 : 0;
        y = i - x;
        while (x <= row - 1 && y >= 0) {
            cout << array[x][y] << endl;
            x = x + 1;
            y = y - 1;
        }
    }
    return 0;
}
