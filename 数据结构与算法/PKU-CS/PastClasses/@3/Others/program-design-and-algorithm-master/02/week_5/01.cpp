#include<iostream>
using namespace std;

int main()
{
	int k = 0;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int m = 0, n = 0, sum = 0;
		cin >> m >> n;
		for (int p = 0; p < m; p++)
		{
			for (int q = 0; q < n; q++)
			{
				int a = 0;
				cin >> a;
				if (p == 0 || p == m - 1 || q == 0 || q == n - 1)
				{
					sum += a;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}