#include<iostream>

using namespace std;

void handleEven(int);

void handleOdd(int n) {
	int result = n * 3 + 1;
	cout << n << "*3+1=" << result << endl;

	if (result == 1)
		cout << "End" << endl;
	else
	{
		if (result % 2 == 0)
			handleEven(result);
		else
			handleOdd(result);
	}
}

void handleEven(int n) {
	int result = n / 2;
	cout << n << "/2=" << result << endl;
	if (result == 1)
		cout << "End" << endl;
	else
	{
		if (result % 2 == 0)
			handleEven(result);
		else
			handleOdd(result);
	}
}

int main() {
	int n;

	cin >> n;

	if (n == 1)
		cout << "End" << endl;
	else
	{
		if (n % 2 == 0)
			handleEven(n);
		else
			handleOdd(n);
	}

	return 0;
}