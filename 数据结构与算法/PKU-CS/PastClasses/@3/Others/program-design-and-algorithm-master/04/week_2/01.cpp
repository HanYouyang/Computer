#include <iostream>
#include <cmath>
using namespace std;

bool guess(int ** wall, int ** brush, int n) {
	int c, r;
	for (r = 1; r < n; r++)
		for (c = 1; c < n + 1; c++)
		{
			brush[r + 1][c] = (wall[r][c] + brush[r][c] + brush[r - 1][c] + brush[r][c - 1] + brush[r][c + 1]) % 2;
		}

	for (c = 1; c < n + 1; c++)
		if ((brush[n][c - 1] + brush[n][c] + brush[n][c + 1] + brush[n - 1][c]) % 2 != wall[n][c])
			return false;

	return true;
}

int enumerate(int ** wall, int ** brush, int n) {
	int c;
	int min = -1;
	int t = 0;
	int total = pow(2, n);

	for (c = 0; c < n + 2; c++)
		brush[1][c] = 0;

	while (t++ < total)
	{
		// refresh brush
		for (int i = 2; i < n + 1; i++)
			for (int j = 1; j < n + 1; j++)
				brush[i][j] = 0;

		if (guess(wall, brush, n))
		{
			int count = 0;
			for (int i = 1; i < n + 1; i++)
				for (int j = 1; j < n + 1; j++)
					count += brush[i][j];

			if (count == 0)
				return 0;

			if (min = -1 || count < min)
				min = count;
		}

		brush[1][1]++;
		c = 1;
		while (brush[1][c]>1)
		{
			brush[1][c] = 0;
			c++;
			brush[1][c]++;
		}
	}

	return min;
}

int main() {
	int t;
	cin >> t;
while (t-- > 0)
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			char c;
			cin >> c;
			if (c == 'y')
				cout << 0 << endl;
			else
				cout << 1 << endl;
			
			continue;
		}
		
		// create 2d array
		int ** wall = new int *[n + 1];
		int ** brush = new int * [n + 1];
		for (int i = 0; i < n + 1; i++)
		{
			wall[i] = new int[n + 2];
			brush[i] = new int[n + 2];
		}

		// init array
		for (int i = 0; i < n + 1; i++)
		{
			for (int j = 0; j < n + 2; j++)
			{
				brush[i][j] = 0;
			}
			wall[i][0] = 0;
			wall[i][n + 1] = 0;
		}

		// input
		char c;
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				cin >> c;
				if (c == 'y')
					wall[i][j] = 0;
				else
					wall[i][j] = 1;
			}
		}

		int min = enumerate(wall, brush, n);
		if (min == -1)
			cout << "inf" << endl;
		else
			cout << min << endl;
	}
	return 0;
}