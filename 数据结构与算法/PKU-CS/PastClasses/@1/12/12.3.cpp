#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    int n;
    double l;
    double dis = 0;
    cin >> n;
    double a[n][2];
    for (int i = 0; i < n; i++){

        cin >> a[i][0] >> a[i][1];
    }
    for(int i = 0; i< n; i++){
        for (int j = 0; j < i; j++){
            l =(a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]);
            if (dis < l)
                dis = l;
        }
    }
    dis = sqrt(dis);
    cout << fixed << setprecision(4) << dis << endl;

}
