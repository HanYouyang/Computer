#include<iostream>

using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	char coma;

	for (int i = 1; i <= 5; i++)
	{
		switch (i)
		{
		case 1:
			cin >> a;
			break;
		case 3:
			cin >> b;
			break;
		case 5:
			cin >> c;
			break;
		default:
			cin >> coma;
			break;
		}
	}

	if (a + b == c)
		cout << '+' << endl;
	else if (a - b == c)
		cout << '-' << endl;
	else if (a * b == c)
		cout << '*' << endl;
	else if (b != 0 && a / b == c)
		cout << '/' << endl;
	else if (b !=0 && a % b == c)
		cout << '%' << endl;
	else
		cout << "error" << endl;

	return 0;
}