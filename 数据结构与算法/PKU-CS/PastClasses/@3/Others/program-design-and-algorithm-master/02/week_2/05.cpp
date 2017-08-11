#include<iostream>
#include<iomanip>

using namespace std;

void exchangeArray(int a[], int b[]) {
	int tmp[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		tmp[i] = a[i];
		a[i] = b[i];
		b[i] = tmp[i];
	}
}

int main() {
	int n;
	int dish[100][4] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> dish[i][0] >> dish[i][1] >> dish[i][2];
		dish[i][3] = (dish[i][2] - dish[i][1]) * 10000 / dish[i][1];
	}

	for (int i = 0; i <	n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (dish[j][3] < dish[i][3])
				exchangeArray(dish[j], dish[i]);
		}
	}

	int trigger = 0, leak = 0, strong = 0;

	for (int i = 1; i < n; i++)
	{
		if (dish[i][3] / dish[i - 1][3] > 1)
		{
			trigger = i;
			leak = i;
			strong = n - i;
			break;
		}
	}

	cout << strong << endl;
	for (int i = trigger; i < n; i++)
	{
		cout << dish[i][0] << endl;
	}
	cout << leak << endl;
	for (int i = 0; i < trigger; i++)
	{
		cout << dish[i][0] << endl;
	}
	return 0;
}