#include <iostream>;
using namespace std;

int countH(int n);
int countV(int n);

int count(int n) {
	if (n == 0)
		return 1;
	else if (n == 2)
		return 3;
	else
		return countH(n) + countV(n);
}

int countH(int n) {
	if (n == 0) 
		return 1;

	if (n == 1)
		return 0;

	return 2 * countV(n - 1) + countH(n - 2);
}

int countV(int n) {
	if (n == 0) 
		return 0;

	if (n == 1)
		return 1;

	return countH(n - 1) + countV(n - 2);
}

int main() {
	int n;
	int total;

	while (1)
	{
		cin >> n;
		if (n == -1)
			break;

		// n can not be even
		if (n % 2 == 1)
		{
			cout << 0 << endl;
			continue;
		}

		total = count(n);

		cout << total << endl;
	}

	return 0;
}