#include "iostream"
#include <stdlib.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int mineven = 65535, maxodd = 0;
	for (int i = 0; i < 6; ++i)
	{
		int temp;
		cin >> temp;
		if (temp % 2 == 0 && temp < mineven)
		{
			mineven = temp;
		}
		if (temp % 2 == 1 && temp > maxodd)
		{
			maxodd = temp;
		}
	}
	cout << abs(mineven - maxodd);
	return 0;
}