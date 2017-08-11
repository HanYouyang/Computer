#include<iostream>
#include<iomanip>
using namespace std;
 
int main() {
	char input[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> input[i][j];
		}
	}
	
	int m, n;
	cin >> m >> n;
	
	if ((m >= 0 && m <= 4) && (n >= 0 && n <= 4)) {
		for (int i = 0; i < 5; i++) {
			if (i == m && i != n) {
				for (int j = 0; j < 5; j++) {
					cout << setw(4) << input[n][j];
				}
				cout << endl;
			}
			if (i == n&&i!=m) {
				for (int j = 0; j < 5; j++) {				
					cout << setw(4) << input[m][j];
				}
				cout << endl;
			}
			if (i != m && i != n) {
				for (int j = 0; j < 5; j++) {
					cout << setw(4) << input[i][j];
                }
				cout << endl;
			}
			if (i == m && m == n) {
				for (int j = 0; j < 5; j++) {
					cout << setw(4) << input[i][j];
				}
				cout << endl;
			}
		}
	} else {
		cout << "error" << endl;
	} 
	
	return 0;
}
