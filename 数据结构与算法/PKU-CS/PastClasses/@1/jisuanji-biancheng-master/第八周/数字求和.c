#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a, sum = 0;
	cin >> a;
	for (int i = 0; i < 5; ++i)
	{
		int number = 0;
		cin >> number;
		if (number < a)
		{
			sum += number;
		}
	}
	cout << sum;
	return 0;
}