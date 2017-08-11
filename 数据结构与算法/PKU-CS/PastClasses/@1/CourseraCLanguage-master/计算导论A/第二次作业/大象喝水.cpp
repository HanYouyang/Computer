#include<iostream>
#include<stdlib.h>
#define Pi 3.14159
using namespace std;
int main2(){
	int h, r, count;
	cin >> h;
	cin >> r;
	int square = Pi*r*r*h;
	count = 20000 / square + 1;
	cout << count;
	system("pause");
	return 0;
}