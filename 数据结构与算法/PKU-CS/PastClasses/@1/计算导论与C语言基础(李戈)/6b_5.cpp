#include <iostream>
using namespace std;

int main() {
	int n = 0, x = 0;
	cin >> n;
	x = n / 100;
	cout << x << endl;
	n = n % 100;
	x = n / 10;
	cout << x << endl;
	n = n % 10;
	cout << n << endl;	
	return 0;
}
