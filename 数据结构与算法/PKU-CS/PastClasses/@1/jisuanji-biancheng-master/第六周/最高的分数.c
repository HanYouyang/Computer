#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int n,max = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		if (temp > max)
		{
			max = temp;
		}
	}
	cout << max;
	return 0;
}