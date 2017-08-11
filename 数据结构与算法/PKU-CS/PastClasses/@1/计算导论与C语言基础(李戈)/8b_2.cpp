#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	const int t1 = 27, t2 = 23;
	const double v1 = 1.2, v2 = 3.0;
	double walk, bike;
	for (int i = 0; i < n; i++) {
		walk = a[i] / v1;
		bike = a[i] / v2 + t1 + t2;
		if (bike < walk) {
			cout << "Bike" << endl;
		} else if (bike > walk) {
			cout << "Walk" << endl;
		} else {
			cout << "All" << endl;
		}
	}	
	return 0;
}
