#include <iostream>
using namespace std;
int main() {
	int a, b, result;
	cin >> a >> b;
	result = (a + b - a % 2 + b % 2) * (b - a + b % 2 + a % 2) / 4;
	cout << result << endl;
	return 0;
}