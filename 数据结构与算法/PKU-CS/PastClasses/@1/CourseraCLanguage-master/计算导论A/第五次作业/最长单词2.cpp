#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main3(){
	char c; int i = 0,j=0,max=0,result=-1;
	char s[100][20];
	while ((c = getchar()) != '.'){
		if (c == ' '){			
			s[i][j] = 0;
			j = 0;
			i++;
		}
		else{
			s[i][j] = c;
			j++;
			if (j > max){
				max = j;
				result = i;
			}
		}
	}
	s[i][j] = 0;
	printf("%s", s[result]);
	system("pause");
	return 0;
}