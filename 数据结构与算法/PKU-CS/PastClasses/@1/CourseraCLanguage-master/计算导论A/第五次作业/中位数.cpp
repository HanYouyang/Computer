#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void bubblesort(int *a, int n){
	int temp;
	for (int i = 1; i < n; i++){
		for (int j = n-1; j >= i; j--){
			if (a[j] < a[j - 1]){
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}
int main7(){
	int n,a[15000];
	cin >> n;
	while (n != 0){
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		bubblesort(a, n);
		int mid = n / 2;
		if (n % 2 == 0){
			cout << (a[mid] + a[mid - 1]) / 2<<endl;
		}
		else{
			cout << a[mid]<<endl;
		}
		n = 0;
		cin >> n;
	}
	system("pause");
	return 0;
}