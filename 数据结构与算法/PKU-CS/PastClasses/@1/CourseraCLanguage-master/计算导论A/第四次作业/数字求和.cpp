#include<iostream>
#include<stdlib.h>
using namespace std;
int main1(){
	int a, num[5],result=0;
	cin >> a;
	for (int i = 0; i < 5; i++){
		cin >> num[i];
		if (num[i] < a){
			result += num[i];
		}
	}
	cout << result;
	system("pause");
	return 0;
}