#include<iostream>

using namespace std;

int main() {
	int m = 0, k = 0;
	int bit[5] = { 0 };
	int total = 0;

	cin >> m >> k;

	if (m % 19 == 0) {
		for (int i = 1; i <= 5; i++)
		{
			bit[i - 1] = m % 10;
			m = m / 10;
		}

		for (int i = 0; i < 5; i++)
		{
			if (bit[i] == 3)
				total++;
		}

		if (total == k)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	else
		cout << "NO" << endl;

	return 0;
}