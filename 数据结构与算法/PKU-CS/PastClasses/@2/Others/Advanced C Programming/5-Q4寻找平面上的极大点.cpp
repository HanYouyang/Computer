#include <iostream>
using namespace std;
//寻找平面上的极大点
int main(){
     int n, l = 0;
     cin >> n;
     int a[101][2], b[101][2];

     for(int i = 0; i < n; ++i)
         cin >> a[i][0] >> a[i][1];

     for(int i = 0; i < n; ++i){
         bool badPoint = false;
         for(int j = 0; j < n; ++j)
         {
             if(a[i][0] <= a[j][0] && a[i][1] <= a[j][1] && i != j){
                 badPoint = true;
                 break;
             }
         }
         if(!badPoint){
             b[l][0] = a[i][0];
             b[l][1] = a[i][1];
             l++;
         }
     }

     for(int i = 1; i < l; ++i){
         for (int j = 0; j < i; ++j){
             if(b[j][0]>b[i][0] || (b[j][0] == b[i][0] && b[j][1]>b[i][1])){
                 int temp[2];
                 temp[0] = b[j][0];
                 temp[1] = b[j][1];
                 b[j][0] = b[i][0];
                 b[j][1] = b[i][1];
                 b[i][0] = temp[0];
                 b[i][1] = temp[1];
             }
         }
     }

     for(int i = 0; i < l - 1; ++i)
         cout << "(" << b[i][0] << "," << b[i][1] << "),";

     cout << "(" << b[l - 1][0] << "," << b[l-1][1] << ")";

     return 0;
 }
