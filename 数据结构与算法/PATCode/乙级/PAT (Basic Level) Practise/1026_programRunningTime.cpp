#include <iostream>
#include <iomanip>
//#include <cmath>


using namespace std;
//You should modified the int type of CLK_TCK into double when use the code
//of sumSecond = round((c2 - c1) / CLK_TCK);
const int CLK_TCK = 100;

int main()
{
	long long c1, c2;
	long long sumSecond = 0;
	cin >> c1 >> c2;
	//sumSecond = round((c2 - c1) / CLK_TCK);
	//This methods can avoid use float type.
	if((c2 - c1) % CLK_TCK >= 50)
		sumSecond = (c2 - c1) / CLK_TCK + 1;
	else
		sumSecond = (c2 - c1) / CLK_TCK;
	int hour = sumSecond / 3600;
	int minitue = sumSecond % 3600 / 60;
	int second = sumSecond % 60;
	cout << setfill('0')
		<< setw(2) << hour << ':'
		<< setw(2) << minitue << ':'
		<< setw(2) << second;
	return 0;
}
