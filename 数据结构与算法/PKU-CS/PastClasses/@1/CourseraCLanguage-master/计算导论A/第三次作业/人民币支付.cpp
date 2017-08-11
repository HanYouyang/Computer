#include<iostream>
#include<stdlib.h>
using namespace std;
int main4(){
	int n, n100, n50, n20, n10, n5, n1;
	cin >> n;
	n100 = n / 100;
	int remain = n % 100;
	n50 = remain / 50;
	remain = remain % 50;
	n20 = remain / 20;
	remain = remain % 20;
	n10 = remain / 10;
	remain = remain % 10;
	n5 = remain / 5;
	remain = remain % 5;
	n1 = remain;
	cout << n100 << endl;
	cout << n50 << endl;
	cout << n20 << endl;
	cout << n10 << endl;
	cout << n5 << endl;
	cout << n1 << endl;
	system("pause");
	return 0;
}