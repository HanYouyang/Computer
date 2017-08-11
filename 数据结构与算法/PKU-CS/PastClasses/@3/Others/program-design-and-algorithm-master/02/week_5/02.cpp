#include<iostream>

using namespace std;

int main() {
	int a[99][99] = { 0 };
	int m = 0, n = 0;

	cin >> m >> n;


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i <= m + n - 2; i++)
	{
		int start = (i < n) ? 0 : i - n + 1;
		int end = (i <= m - 1) ? i : m - 1;

		for (int j = start; j <= end; j++)
		{
			cout << *(a[j] + (i - j)) << endl;
		}
	}
	return 0;
}