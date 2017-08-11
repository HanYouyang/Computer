#include<iostream>
#include<stdlib.h>
using namespace std;
int main3(){
	int n, m;
	cin >> n;
	if (n >= 95 && n <= 100){
		m = 1;
	}
	else if (n >= 90 && n < 95){
		m = 2;
	}
	else if (n >= 85 && n < 90){
		m = 3;
	}
	else if (n >= 80 && n < 85){
		m = 4;
	}
	else if (n >= 70 && n < 80){
		m = 5;
	}
	else if (n >= 60 && n < 70){
		m = 6;
	}
	else{
		m = 7;
	}
	cout << m;
	system("pause");
	return 0;
}