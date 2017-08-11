#include <iostream>
using namespace std;

int main() {
	int Num1, Num2;
	char opt;
	cin >> Num1 >> Num2 >> opt;
	
	switch (opt) {
		case '+':
			cout << Num1 + Num2 << endl;
			break;
		case '-':
			cout << Num1 - Num2 << endl;
			break;
		case '*':
			cout << Num1 * Num2 << endl;
			break;
		case '/':
			if (Num2) {
				cout << Num1 / Num2 << endl;
			} else {
				cout << "Divided by zero!" << endl;
			}
			break;
		default:
			cout << "Invalid operator!" << endl;
			break;
	}
	
	return 0;
}
