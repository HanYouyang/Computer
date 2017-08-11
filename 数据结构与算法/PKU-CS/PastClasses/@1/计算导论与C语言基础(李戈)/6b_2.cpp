#include <iostream>
using namespace std;

int main() {
	int h = 0, r = 0;
	cin >> h >> r;
	const float PI = 3.14159;
	float volume = 0;
	volume = PI * r * r * h / 1000;
	int number = 0;
	number = (int) (20 / volume + 1);
	cout << number;
	return 0;
}
