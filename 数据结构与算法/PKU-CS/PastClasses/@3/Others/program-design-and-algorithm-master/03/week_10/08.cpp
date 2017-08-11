#include <iostream>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;

	while (t > 0)
	{
		int n, i, j, k = 0;
		cin >> n >> i >> j;

		// if n[i] == 1, then k[i] = 1
		if (n & (1 << i))
			k |= (1 << i);

		// if n[j] != 1, then k[j] = 1
		if (!(n & (1 << j)))
			k |= (1 << j);

		for (int z = i + 1; z < j; z++)
			k |= (1 << z);

		cout << hex << k << endl;
		t--;
	}
	return 0;
}