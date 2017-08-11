#include<iostream>
#include<stdlib.h>
using namespace std;
int main4(){
	int n, k,num[1000];
	cin >> n; cin >> k;
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if ((num[i] + num[j]) == k){
				cout << "yes";
				return 0;
			}
		}
	}
	cout << "no";
	system("pause");
	return 0;
}