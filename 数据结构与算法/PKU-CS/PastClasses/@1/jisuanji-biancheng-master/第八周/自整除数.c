#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 10; i < n; ++i)		
	{
		int sum;
		sum = i/10 + i%10;
		if (i%sum == 0)
		{
			cout << i << endl;
		}
	}
	return 0;
}