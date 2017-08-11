#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void reverse(int *a, int low,int high){
	int temp;
	while (low < high){
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
		low++; high--;
	}
}
int main6(){
	int n, m, a[100];
	cin >> n; cin >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	reverse(a, 0, n - m - 1);
	reverse(a, n - m, n - 1);
	reverse(a, 0, n - 1);
	for (int i = 0; i < n; i++){
		cout << a[i]<<" ";
	}
	system("pause");
	return 0;
}