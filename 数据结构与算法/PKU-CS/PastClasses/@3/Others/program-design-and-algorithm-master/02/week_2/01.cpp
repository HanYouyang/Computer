#include<iostream>

using namespace std;

int main() {
	int n = 0;
	int a[100] = { 0 };
	bool ifExists = false;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == i)
		{
			cout << a[i] << endl;
			ifExists = true;
			break;
		}
	}

	if (!ifExists)
		cout << 'N' << endl;

	return 0;
}