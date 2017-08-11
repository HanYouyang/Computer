#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float sum[6];
	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			char b;
			cin >> b;
			float c;
			cin >> c;
			sum[a - 1] = sum[a - 1] + c;
			if (b == 'A') {				
				sum[3] = sum[3] + c;
			} else if (b == 'B') {
				sum[4] = sum[4] + c;
			} else if (b == 'C') {
				sum[5] = sum[5] + c;
			}
		}
	}
	cout << fixed << setprecision(2);
	cout << "1 " << sum[0] << endl;
	cout << "2 " << sum[1] << endl;
	cout << "3 " << sum[2] << endl;
	cout << "A " << sum[3] << endl;
	cout << "B " << sum[4] << endl;
	cout << "C " << sum[5] << endl;
	return 0;
}
