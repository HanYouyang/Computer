#include<iostream>

using namespace std;

struct dot {
	int x;
	int y;
	bool max;
};

int main() {
	int n = 0;
	dot dots[100] = { 0 ,0 , false};

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> dots[i].x;
		cin >> dots[i].y;
		dots[i].max = true;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (dots[j].x >= dots[i].x && dots[j].y >= dots[i].y)
				{
					dots[i].max = false;
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		dot tmp = dots[i];
		if (dots[i].max == true)
			continue;

		for (int j = i + 1; j < n; j++)
		{
			if (dots[j].max == true)
			{
				tmp = dots[j];
				dots[j] = dots[i];
				dots[i] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (dots[i].max == false)
			break;

		dot tmp;
		for (int j = i + 1; j < n; j++)
		{
			if (dots[j].max == false)
				break;

			if (dots[i].x > dots[j].x)
			{
				tmp = dots[i];
				dots[i] = dots[j];
				dots[j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (dots[i].max == false)
			break;

		cout << '(' << dots[i].x << ',' << dots[i].y << ')';

		if (dots[i + 1].max == true)
			cout << ',';
	}

	cout << endl;
	return 0;
}