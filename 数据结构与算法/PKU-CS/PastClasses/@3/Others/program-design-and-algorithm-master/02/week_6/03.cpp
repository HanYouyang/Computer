#include<iostream>
#include <iomanip>

using namespace std;

int main() {
	int m = 0, n = 0;
	int field[20][20] = { 0 };

	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> field[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					if (field[i][j] >= field[i][j + 1] && field[i][j] >= field[i + 1][j])
						cout << i << ' ' << j << endl;
				}
				else if (j == n - 1)
				{
					if(field[i][j] >= field[i][j - 1] && field[i][j] >= field[i + 1][j])
						cout << i << ' ' << j << endl;
				}
				else
				{
					if (field[i][j] >= field[i][j - 1] && field[i][j] >= field[i][j + 1] && field[i][j] >= field[i + 1][j])
						cout << i << ' ' << j << endl;
				}
			}
			else if (i == m - 1)
			{
				if (j == 0)
				{
					if (field[i][j] >= field[i][j + 1] && field[i][j] >= field[i - 1][j])
						cout << i << ' ' << j << endl;
				}
				else if (j == n - 1)
				{
					if (field[i][j] >= field[i][j - 1] && field[i][j] >= field[i - 1][j])
						cout << i << ' ' << j << endl;
				}
				else
				{
					if (field[i][j] >= field[i][j - 1] && field[i][j] >= field[i][j + 1] && field[i][j] >= field[i - 1][j])
						cout << i << ' ' << j << endl;
				}
			}
			else if (j == 0)
			{
				if (field[i][j] >= field[i - 1][j] && field[i][j] >= field[i + 1][j] && field[i][j] >= field[i][j + 1])
					cout << i << ' ' << j << endl;
			}
			else if (j == n - 1)
			{
				if (field[i][j] >= field[i - 1][j] && field[i][j] >= field[i + 1][j] && field[i][j] >= field[i][j - 1])
					cout << i << ' ' << j << endl;
			}
			else
			{
				if (field[i][j] >= field[i - 1][j] && field[i][j] >= field[i + 1][j] && field[i][j] >= field[i][j - 1] && field[i][j] >= field[i][j + 1])
					cout << i << ' ' << j << endl;
			}
		}
	}

	return 0;
}