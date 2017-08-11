#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

bool ifLeapYear(int year) {
	bool ifLeap = false;
	if (year % 4 == 0 && year % 100 != 0)
		ifLeap = true;
	else if (year % 400 == 0)
		ifLeap = true;
	return ifLeap;
}

int main() {
	char date[11] = { '\0' };
	char strY[5] = { '\0' };
	char strM[3] = { '\0' };
	char strD[3] = { '\0' };
	int intY = 0, intM = 0, intD = 0;
	int nextY = 0, nextM = 0, nextD = 0;

	cin.getline(date, 11, '\0');

	for (int i = 0; i < 4; i++)
	{
		strY[i] = date[i];
	}

	for (int i = 0; i < 2; i++)
	{
		strM[i] = date[i + 5];
	}

	for (int i = 0; i < 2; i++)
	{
		strD[i] = date[i + 8];
	}
	intY = atoi(strY);
	intM = atoi(strM);
	intD = atoi(strD);
	nextY = intY;
	nextM = intM;
	nextD = intD;

	bool ifLeap = ifLeapYear(intY);
	if (intM == 12)
	{
		if (intD == 31)
		{
			nextY++;
			nextM = 1;
			nextD = 1;
		}
		else
		{
			nextD++;
		}
	}

	if (intM == 2)
	{
		if (intD == 28 && !ifLeap || intD == 29)
		{
			nextM++;
			nextD = 1;
		}
		else
		{
			nextD++;
		}
	}

	if (intM == 1 || intM == 3 || intM == 5 || intM == 7 || intM == 8 || intM == 10)
	{
		if (intD == 31)
		{
			nextM++;
			nextD = 1;
		}
		else
		{
			nextD++;
		}
	}

	if (intM == 4 || intM == 6 || intM == 9 || intM == 11)
	{
		if (intD == 30)
		{
			nextM++;
			nextD = 1;
		}
		else
		{
			nextD++;
		}
	}

	cout << nextY << '-' << setfill('0') << setw(2) << nextM << '-' << nextD << endl;
	return 0;
}