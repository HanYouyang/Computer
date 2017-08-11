#include <iostream>
#include <cstdio>
using namespace std;
//Tomorrow never knows？
int main(){
	int year, month, day;
	int dayTable[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
						    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
	int isLeapYear, daysOfMonth;
	scanf("%d-%d-%d", &year, &month, &day);
	isLeapYear = (year % 4 == 0 && year % 100 != 0)|| (year %400 == 0);
	daysOfMonth = dayTable[isLeapYear][month];
	++day;
	if(day > daysOfMonth) {
		day = 1;
		++month;
	}	
	if(month > 12) {
		month = 1;
		++year;
	}
	printf("%d-%02d-%02d\n", year, month, day);
	return 0;
}