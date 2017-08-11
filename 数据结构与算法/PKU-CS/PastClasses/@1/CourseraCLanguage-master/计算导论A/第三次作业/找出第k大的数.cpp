#include<iostream>
#include<stdlib.h>
using namespace std;
void maxton(int *num,int n){
	int max =0;
	for (int i = 1; i < n; i++){
		if (num[max] < num[i]){
			max = i;
		}
	}
	if (max != n - 1){
		int temp = num[max];
		num[max] = num[n - 1];
		num[n - 1] = temp;
	}
}
int main444(){
	int n, k, num[100];
	cin >> n; cin >> k;
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	for (int i = 0; i < k; i++){
		maxton(num, n - i);
	}
	cout << num[n - k];
	system("pause");
	return 0;
}