#include <iostream>
using namespace std;

int main() {
	int n = 0, x = 0, y =0;
	cin >> n >> x >> y;
	int eat = 0, remain = 0;
	if (y % x == 0) {
		eat = y / x;
	} else {
		eat = y / x + 1;
	}
	if (n > eat) {
		remain = n - eat;
	}
	cout << remain;
	return 0;
}
