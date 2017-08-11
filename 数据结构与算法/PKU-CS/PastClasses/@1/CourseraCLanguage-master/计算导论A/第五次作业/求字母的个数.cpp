#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main1(){
	char s[80] = {0};
	int a=0, e=0, i=0, o=0, u=0;
	gets(s);
	for (int j = 0; j < 80; j++){
		switch (s[j]){
		case 'a':
			a++;
			break;
		case 'e':
			e++;
			break;
		case 'i':
			i++;
			break;
		case 'o':
			o++;
			break;
		case 'u':
			u++;
			break;
		}
	}
	cout << a << " " << e << " " << i << " " << o << " " << u;
	system("pause");
	return 0;
}