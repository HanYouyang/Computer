#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
//最远距离
int main(){
    int nSize;
    cin >> nSize;

    float point[nSize][2];
    for(int i = 0; i < nSize; i++){
        cin >> point[i][0] >> point[i][1];
    }

    double max = 0;
    for(int i = 0; i < nSize-1; i++){
        for(int j = i+1; j < nSize ; j++){
            double distance = sqrt( pow((point[i][0]-point[j][0]),2) + pow((point[i][1]-point[j][1]),2) );
            if(distance >= max){
                max = distance;
            }
        }
    }

    printf("%.4f\n", max);

    return 0;
}
