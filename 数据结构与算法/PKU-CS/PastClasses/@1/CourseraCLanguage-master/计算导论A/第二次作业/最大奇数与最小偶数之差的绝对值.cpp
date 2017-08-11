#include<iostream>
#include<stdlib.h>
using namespace std;
int main4(){
	int num[6];
	for (int i = 0; i < 6; i++){
		cin >> num[i];
	}
	int minEven = 100, maxOdd = 0;
	for (int i = 0; i < 6; i++){
		if (num[i] % 2 == 0 && num[i] < minEven){
			minEven = num[i];
		}
		if (num[i] % 2 == 1 && num[i]>maxOdd){
			maxOdd = num[i];
		}
	}
	if (minEven - maxOdd>0){
		cout << (minEven-maxOdd);
	}
	else{
		cout << (maxOdd-minEven);
	}
	system("pause");
	return 0;
}