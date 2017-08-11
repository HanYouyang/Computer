#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main(){
	int y, m, d;
	scanf("%d-%d-%d", &y, &m, &d);
	int isleapyear = y % 400 == 0 || (y%4==0&&y%100!=0);
	switch (m){
	case 1:case 3: case 5: case 7:case 8:case 10:
		if (d== 31){
			d = 1;m++;
		}
		else{
			d++;
		}		
		break;
	case 2:
		if (isleapyear){
			if (d == 29){
				d=1; m++;
			}
			else{
				d++;
			}
		}
		else{
			if (d == 28){
				d = 1; m++;
			}
			else{
				d++;
			}
		}
		break;
	case 4:case 6:case 9:case 11:
		if (d == 30){
			d = 1; m++;
		}
		else{
			d++;
		}
		break;
	case 12:
		if (d == 31){
			d = 1; m = 1; y++;
		}
		else{
			d++;
		}
		break;
	}
	printf("%d-%02d-%02d\n", y, m, d);
	system("pause");
	return 0;
}