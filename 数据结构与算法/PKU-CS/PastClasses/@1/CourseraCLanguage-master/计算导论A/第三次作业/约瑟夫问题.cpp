#include<iostream>
#include<stdlib.h>
using namespace std;
int king(int n, int m){
	int monkey[300] = {0};
	int count = 0,index=1;
	int remain = n;
	while (remain > 1){
		if (monkey[index] == 0){
			count++;
			if (count == m){
				count = 0;
				monkey[index] = 1;
				remain--;
			}
		}
		if (index == n){
			index = 1;
		}
		else{
			index++;
		}
	}
	for (int i = 1; i <= n; i++){
		if (monkey[i] == 0){
			return i;
		}
	}
}
int main1(){
	int n, m,num[100],i=0;
	cin >> n;
	cin >> m;
	while (m != 0 && n != 0){
		num[i] = king(n, m);
		cin >> n;
		cin >> m;
		i++;
	}
	for (int j = 0; j < i; j++){
		cout << num[j] << endl;
	}
	system("pause");
	return 0;
}
