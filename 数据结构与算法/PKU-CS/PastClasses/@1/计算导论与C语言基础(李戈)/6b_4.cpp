#include <iostream>
using namespace std;

int main() {
	int a[6];
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	int min_0 = 98, max_1 = 1;
	for (int i = 0; i < 6; i++) {
		if (a[i] % 2 == 0) {
			if (a[i] < min_0) {
				min_0 = a[i];
			}
		} else {
			if (a[i] > max_1) {
				max_1 = a[i];
			}
		}		
	}
	int difference = 0;
	if (min_0 > max_1) {
		difference = min_0 - max_1;
	} else {
		difference = max_1 - min_0;
	}
	cout << difference;
	return 0;
}
