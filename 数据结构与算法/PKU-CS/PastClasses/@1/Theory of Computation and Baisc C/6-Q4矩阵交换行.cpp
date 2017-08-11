#include <iostream>
#include <iomanip>
using namespace std;
//矩阵交换行
int main(){
    int matrix[5][5], n, m;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> matrix[i][j];
        }
    }

    cin >> n >> m;

    int store[5];
    if( n >= 0 && n <= 4 && m >= 0 && m <= 4){
        for(int i = 0; i < 5; i++){
            store[i] = matrix[m][i];
        }
        for(int i = 0; i < 5; i++){
            matrix[m][i] = matrix[n][i];
        }
        for(int i = 0; i < 5; i++){
            matrix[n][i] = store[i];
        }

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cout << setw(4) << matrix[i][j];
            }
            cout << endl;
        }
    }else{
        cout << "error" << endl;
    }

    return 0;
}
