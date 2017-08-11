#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main3(){
	int k,n1=0,n5=0,n10=0,n;
	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> n;
		if (n == 1){
			n1++;
		}
		else if(n==5){
			n5++;
		}
		else if (n==10){
			n10++;
		}
	}
	cout << n1 << endl;
	cout << n5 << endl;
	cout << n10 << endl;
	system("pause");
	return 0;
}