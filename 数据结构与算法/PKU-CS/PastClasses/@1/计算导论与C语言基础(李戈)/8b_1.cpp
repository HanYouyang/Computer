#include <iostream>
using namespace std;

int main() {
	int a, tmp, sum = 0;
	cin >> a;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		if (tmp < a) {
			sum = sum + tmp;
		}
	}
	cout << sum << endl;
	return 0;
}
