#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main3(){
	float n, k;
	while (scanf("%f %f", &n, &k) != EOF){
		int i;
		float price=200;
		for (i = 1; i <= 20; i++){
			if ((n*i*1.0f) > price){
				break;
			}
			price = price*(1 + k / 100.0f);
		}
		if (i == 21){
			cout << "Impossible"<<endl;
		}
		else{
			cout << i << endl;
		}
	}
	system("pause");
	return 0;
}