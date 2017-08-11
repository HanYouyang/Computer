#include <iostream>
using namespace std;
//流感传染
int main(){
    int n, m;
    cin >> n;
    char matrix[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    cin >> m;

    for(int k = 1; k < m; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '@'){
                    if(i - 1 >= 0 && matrix[i - 1][j] =='.')
                        matrix[i - 1][j] = '*';
                    if(i + 1 < n && matrix[i + 1][j] == '.')
                        matrix[i + 1][j] = '*';
                    if(j - 1 >= 0 && matrix[i][j - 1] =='.')
                        matrix[i][j - 1] = '*';
                    if(j + 1 < n && matrix[i][j + 1] == '.')
                        matrix[i][j + 1] = '*';
                }
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == '*')
                    matrix[i][j] = '@';
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(matrix[i][j] == '@')
                sum += 1;

    cout << sum << endl;
    return 0;
}
