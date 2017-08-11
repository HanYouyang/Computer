#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	float personCount[3] = { 0.0 }, classCount[3] = { 0.0 };

	for (int i = 0; i < 3; i++)
	{
		int person = 0;
		int num = 0;
		cin >> person >> num;
		for (int j = 0; j < num; j++)
		{
			char c;
			float price = 0.0;
			cin >> c >> price;

			personCount[person - 1] += price;
			if (c == 'A')
				classCount[0] += price;
			else if (c == 'B')
				classCount[1] += price;
			else
				classCount[2] += price;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ' ' << fixed << setprecision(2) << personCount[i] << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			cout << 'A' << ' ';
			break;
		case 1:
			cout << 'B' << ' ';
			break;
		case 2:
			cout << 'C' << ' ';
			break;
		}
		cout << fixed << setprecision(2) << classCount[i] << endl;
	}

	return 0;
}