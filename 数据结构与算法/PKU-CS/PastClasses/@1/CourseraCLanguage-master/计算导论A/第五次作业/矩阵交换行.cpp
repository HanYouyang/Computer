#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
using namespace std;
int ischange(int a[5][5],int n,int m){
	int temp;
	if (n >= 0 && n < 5 && m >= 0 && m < 5){
		for (int i = 0; i < 5; i++){
			temp = a[n][i];
			a[n][i] = a[m][i];
			a[m][i] = temp;
		}
		return 1;
	}
	else{
		return 0;
	}
}

int main4(){
	int a[5][5],n,m;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			cin >> a[i][j];
		}
	}
	cin >> n; cin >> m;
	if (ischange(a, n, m) == 0){
		cout << "error" << endl;
	}
	else{
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				cout << setw(4) << a[i][j];
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}