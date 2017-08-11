#include <iostream>
using namespace std;

int main() {
	int N, K;
	while (cin >> N >> K) {
		double price = 200.0;
		int money = N, year = 1;
		while (money < price) {
			year = year + 1;
			money = money + N;
			price = price + price * K / 100;
			if (year > 20) {
				cout << "Impossible" << endl;
				break;
			}			
		}
		if (year < 21) {
			cout << year << endl;
		}
	}	
	return 0;
}
