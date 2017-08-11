#include<iostream>

using namespace std;

int arycmp(int a[], int b[]) {
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] == b[i])
			n++;
	}

	return n;
}

int main() {
	int a[24][4] = {
		{ 1, 2, 3, 4 },
		{ 1, 2, 4, 3 },
		{ 1, 3, 2, 4 },
		{ 1, 3, 4, 2 },
		{ 1, 4, 2, 3 },
		{ 1, 4, 3, 2 },
		{ 2, 1, 3, 4 },
		{ 2, 1, 4, 3 },
		{ 2, 3, 1, 4 },
		{ 2, 3, 4, 1 },
		{ 2, 4, 1, 3 },
		{ 2, 4, 3, 1 },
		{ 3, 1, 2, 4 },
		{ 3, 1, 4, 2 },
		{ 3, 2, 1, 4 },
		{ 3, 2, 4, 1 },
		{ 3, 4, 1, 2 },
		{ 3, 4, 2, 1 },
		{ 4, 1, 2, 3 },
		{ 4, 1, 3, 2 },
		{ 4, 2, 1, 3 },
		{ 4, 2, 3, 1 },
		{ 4, 3, 1, 2 },
		{ 4, 3, 2, 1 }
	};

	int test[4][4] = {
		{ 2, 3, 1, 4 },
		{ 4, 1, 3, 2 },
		{ 0, 0, 2, 4 },
		{ 1, 4, 2, 3 }
	};

	for (int i = 0; i < 24; i++)
	{
		bool found = false;
		for (int j = 0; j < 4; j++)
		{
			int result = arycmp(a[i], test[j]);
			if (result == 1)
				found = true;
			else
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << a[i][j] << endl;
			}
			break;
		}
	}


	return 0;
}