#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int main2(){
	char s1[80], s2[80];
	gets(s1); gets(s2);
	for (int i = 0; i < 80; i++){
		if (s1[i] >= 'a'&&s1[i] <= 'z'){
			s1[i] -= 32;
		}
		if (s2[i] >= 'a'&&s2[i] <= 'z'){
			s2[i] -= 32;
		}
	}
	if (strcmp(s1, s2)>0){
		cout << '>';
	}
	else if (strcmp(s1, s2) < 0){
		cout << '<';
	}
	else{
		cout << '=';
	}
	system("pause");
	return 0;
}