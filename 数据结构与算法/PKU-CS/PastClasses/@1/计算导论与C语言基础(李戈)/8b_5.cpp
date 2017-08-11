#include <iostream>
using namespace std;

int divisor(int n) {
	int sum = 0, tmp = n;
	while (tmp > 0) {
		sum = sum + tmp % 10;
		tmp = tmp / 10;		
	}
	if (n % sum == 0) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 10; i <= n; i++) {
		if (divisor(i)) {
			cout << i << endl;
		}
	}
	return 0;
}

