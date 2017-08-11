#include <iostream>
using namespace std;

void move(int m, char x, char y, char z) {
	if (m == 1) {
		cout << x << " --> " << z << endl;
	} else {
		move(m - 1, x, z, y);
		cout << x << " --> " << z << endl;
		move(m - 1, y, x, z);
	}
}

int main() {
	int n;
	cin >> n;
	move(n, 'A', 'B', 'C');
	return 0;
}
