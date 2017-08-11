#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int number[500];
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	
	int j = 0;
	for (int i = n - m; i < n - m / 2; i++) {
		int temp = number[i];
		number[i] = number[n - 1 - j];
		number[n - j - 1] = temp;
		j = j + 1;
	}
	int k = 0;
	for (int i = 0; i < (n-m)/2; i++) {
		int temp = number[i];
		number[i] = number[n-m-k-1];
		number[n -m- k - 1] = temp;
		k = k + 1;
	}
	for (int i = 0; i < n/2; i++) {
		int tmp = number[i];
		number[i] = number[n - 1 - i];
		number[n - i-1] = tmp;
	}
	for (int i = 0; i < n; i++) {
		if( i != n-1) {
			cout<< number[i] << ' ';
		} else {
			cout << number[i] << endl;
		}				
	}
	
	return 0;
}
