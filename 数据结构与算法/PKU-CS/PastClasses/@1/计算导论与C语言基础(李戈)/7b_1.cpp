#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	int tmp = 0, a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp > 60) {
			d = d + 1;
		} else if (tmp > 35) {
			c = c + 1;
		} else if (tmp > 18) {
			b = b + 1;
		} else {
			a = a + 1;
		}
	}
	double A = (double) a / n * 100;
	double B = (double) b / n * 100;
	double C = (double) c / n * 100;
	double D = (double) d / n * 100;
	cout << fixed << setprecision(2);    
    cout << "1-18: " << A << "%" << endl;    
    cout << "19-35: " << B << "%" << endl;    
    cout << "36-60: " << C << "%" << endl;    
    cout << "60-: " << D << "%" << endl;
	return 0;
}
