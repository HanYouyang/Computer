#include <iostream>

using namespace std;
//给出一组无序整数，求出中位数，如果求最中间两个数的平均数，向下取整即可（不需要使用浮点数）
int main(){
    int input, number[100][100], counter = 0, size[100] = {0};

    while(cin >> input && input != 0){
        size[counter] = input;
        for(int i = 0; i < size[counter]; i++){
            cin >> number[counter][i];
        }
        counter += 1;
    }

    for(int i = 0; i < counter; i++){
        for(int j = 0; j < size[i]; j++){
            //对每行数字进行冒泡排序
            for(int k = 0; k < size[i]-1; k++){
                for(int m = 1; m < size[i] - k; m++){
                    if(number[i][m-1] > number[i][m]){
                        int temp = number[i][m];
                        number[i][m] = number[i][m-1];
                        number[i][m-1] = temp;
                    }
                }
            }
        }
        if(size[i] % 2 != 0){
            cout << number[i][size[i]/2];
        }else{
            cout << (number[i][size[i]/2-1] + number[i][size[i]/2])/2;
        }
        cout << "\n";
    }

    return 0;
}

