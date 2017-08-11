#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int number;
	cin >> number;
	cout << number / 100 << endl;
	number = number % 100;
	cout << number / 50 << endl;
	number = number % 50;
	cout << number / 20 << endl;
	number = number % 20;
	cout << number / 10 << endl;
	number = number % 10;
	cout << number / 5 << endl;
	number = number % 5;
	cout << number << endl;
	return 0;
}