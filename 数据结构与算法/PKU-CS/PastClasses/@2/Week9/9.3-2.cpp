#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main(){
	int a, b, c;
	while (scanf("%d,%d,%d", &a, &b, &c)!=EOF){
		if (a + b == c){
			cout << "+" << endl;
		}
		else if (a - b == c){
			cout << "-" << endl;
		}
		else if (a*b == c){
			cout << "*" << endl;
		}
		else if (a / b == c){
			cout << "/" << endl;
		}
		else if (a % b == c){
			cout << "%" << endl;
		}
		else{
			cout << "error" << endl;
		}
	}
	return 0;
}