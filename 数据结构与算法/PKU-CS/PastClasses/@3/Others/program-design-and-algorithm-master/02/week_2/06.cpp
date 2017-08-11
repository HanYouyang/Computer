#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	int n = 0, m = 0, sick = 0;
	char room[100][100] = { '\0' };

	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++)
	{
		cin.getline(room[i], n + 1);
	}

	cin >> m;

	for (int i = 1; i < m; i++)
	{
		// mark
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (room[j][k] == '@')
				{
					// top-left
					if (j == 0 && k == 0)
					{
						if (room[j][k + 1] == '.')
							room[j][k + 1] = 'a';
						if (room[j + 1][k] == '.')
							room[j + 1][k] = 'a';
					}
					// top-right
					else if (j == 0 && k == n - 1)
					{
						if (room[j][k - 1] == '.')
							room[j][k - 1] = 'a';
						if (room[j + 1][k] == '.')
							room[j + 1][k] = 'a';
					}
					// bottom-left
					else if (j == n - 1 && k == 0)
					{
						if (room[j][k + 1] == '.')
							room[j][k + 1] = 'a';
						if (room[j - 1][k] == '.')
							room[j - 1][k] = 'a';
					}
					// bottom-right
					else if (j == n - 1 && k == n - 1)
					{
						if (room[j][k - 1] == '.')
							room[j][k - 1] = 'a';
						if (room[j - 1][k] == '.')
							room[j - 1][k] = 'a';
					}
					// top row
					else if (j == 0)
					{
						if (room[j][k - 1] == '.')
							room[j][k - 1] = 'a';
						if (room[j][k + 1] == '.')
							room[j][k + 1] = 'a';
						if (room[j + 1][k] == '.')
							room[j + 1][k] = 'a';
					}
					// bottom row
					else if (j == n - 1)
					{
						if (room[j][k - 1] == '.')
							room[j][k - 1] = 'a';
						if (room[j][k + 1] == '.')
							room[j][k + 1] = 'a';
						if (room[j - 1][k] == '.')
							room[j - 1][k] = 'a';
					}
					// first column
					else if (k == 0)
					{
						if (room[j][k + 1] == '.')
							room[j][k + 1] = 'a';
						if (room[j + 1][k] == '.')
							room[j + 1][k] = 'a';
						if (room[j - 1][k] == '.')
							room[j - 1][k] = 'a';
					}
					// last column
					else if (k == n - 1)
					{
						if (room[j][k - 1] == '.')
							room[j][k - 1] = 'a';
						if (room[j + 1][k] == '.')
							room[j + 1][k] = 'a';
						if (room[j - 1][k] == '.')
							room[j - 1][k] = 'a';
					}
					else
					{
						if (room[j][k + 1] == '.')
							room[j][k + 1] = 'a';
						if (room[j][k - 1] == '.')
							room[j][k - 1] = 'a';
						if (room[j + 1][k] == '.')
							room[j + 1][k] = 'a';
						if (room[j - 1][k] == '.')
							room[j - 1][k] = 'a';
					}
				}
			}
		}

		// replace
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (room[j][k] == 'a')
					room[j][k] = '@';
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// cout << room[i][j] << ' ';
			if (room[i][j] == '@')
				sick++;
		}
		// cout << endl;
	}

	cout << sick << endl;
	return 0;
}