#include<iostream>
#include<stdlib.h>
using namespace std;
int main5(){
	int n; cin >> n; int point[100][2],res[100][2];
	for (int i = 0; i < n; i++){
		cin >> point[i][0] >> point[i][1];
	}
	int count = 0;
	for (int i = 0; i < n; i++){
		int a = point[i][0], b = point[i][1];
		int flag = 0;//Ã»ÓÐÖ§Åä
		for (int j = 0; j < n; j++){
			if (i != j){
				if (point[j][0]>=a&&point[j][1]>=b){
					flag = 1;
				}
			}
		}
		if (!flag){
			res[count][0] = a; res[count][1] = b; count++;
		}
	}
	for (int i = 1; i < count; i++){
		for (int j = count - 1; j >= i; j--){
			if (res[j - 1][0]>res[j][0]){
				int tempa = res[j - 1][0];
				res[j - 1][0] = res[j][0];
				res[j][0] = tempa;
				int tempb = res[j - 1][1];
				res[j - 1][1] = res[j][1];
				res[j][1] = tempb;
			}
		}
	}
	for (int i = 0; i < count; i++){
		if (i == count - 1){
			cout << "(" << res[i][0] << "," << res[i][1] << ")";
		}
		else{
			cout << "(" << res[i][0] << "," << res[i][1] << "),";
		}
	}
	system("pause");
	return 0;
}