#include<iostream>
#include <iomanip>

using namespace std;

int main() {
	int n = 0;
	char dna[10000][255] = { '\0' };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> dna[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 255; j++)
		{
			if (dna[i][j] == '\0')
				break;

			switch (dna[i][j])
			{
			case 'A':
				cout << 'T';
				break;
			case 'G':
				cout << 'C';
				break;
			case 'T':
				cout << 'A';
				break;
			case 'C':
				cout << 'G';
				break;
			}
		}
		cout << endl;
	}

	return 0;
}