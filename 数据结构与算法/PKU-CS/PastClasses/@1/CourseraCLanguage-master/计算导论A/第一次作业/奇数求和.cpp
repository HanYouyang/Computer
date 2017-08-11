#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main2(){
	int m, n,result=0;
	cin>>m;
	cin >> n;
	for (int i = m; i <= n; i++){
		if (i % 2 == 1){
			result += i;
		}
	}
	cout << result;
	system("pause");
	return 0;
}