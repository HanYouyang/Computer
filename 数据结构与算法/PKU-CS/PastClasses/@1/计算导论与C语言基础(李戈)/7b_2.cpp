#include <iostream>
using namespace std;

int main() {
	int n = 0, m = 0;
	cin >> n;
	if (n >= 95) {
		m = 1;
	} else if (n >= 90) {
		m = 2;
	} else if (n >= 85) {
		m = 3;
	} else if (n >= 80) {
		m = 4;
	} else if (n >= 70) {
		m = 5;
	} else if (n >= 60) {
		m = 6;
	} else {
		m = 7;
	} 
	cout << m;
	return 0;
}
