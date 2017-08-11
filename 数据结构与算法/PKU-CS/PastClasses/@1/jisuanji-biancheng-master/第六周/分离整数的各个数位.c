#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int number;
	cin >> number;
	cout << number / 100 << endl;
	number = number % 100;
	cout << number / 10 << endl;
	number = number % 10;
	cout << number <<endl;
	return 0;
}