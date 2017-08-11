#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = 0, tmp = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] > max) {
				max = a[j];
			}
		}
		for (int j = 0; j < n; j++) {
			if (a[j] == max) {
				a[j] = 0;
				tmp = max;
			}
		}
		max = 0;
	}
	cout << tmp << endl;
	return 0;
}
