#include <iostream>
using namespace std;

int main() {
	int year = 0;
	char isLeap = 'N';
	cin >> year;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		isLeap = 'Y';
	}
	cout << isLeap << endl;
	return 0;
}
