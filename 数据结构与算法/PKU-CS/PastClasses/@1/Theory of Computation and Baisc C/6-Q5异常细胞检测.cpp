#include <iostream>
using namespace std;
//异常细胞检测
int main(){
    int row, column, counter = 0;
    cin >> row;
    column = row;

    int matrix[row][255];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i = 1; i < row - 1; i++){
        for(int j = 1; j < column - 1; j++){
            if( matrix[i-1][j] - matrix[i][j] >= 50
             && matrix[i+1][j] - matrix[i][j] >= 50
             && matrix[i][j-1] - matrix[i][j] >= 50
             && matrix[i][j+1] - matrix[i][j] >= 50){
               counter += 1;
            }
        }
    }

    cout << counter << endl;
    return 0;
}
