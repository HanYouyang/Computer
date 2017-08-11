#include<iostream>
#include<stdlib.h>
using namespace std;
int main1(){
	int n;
	cin >> n;
	if (n % 400 == 0 || (n % 100 != 0 && n % 4 == 0)){
		cout << "Y";
	}
	else{
		cout << "N";
	}
	system("pause");
	return 0;
}