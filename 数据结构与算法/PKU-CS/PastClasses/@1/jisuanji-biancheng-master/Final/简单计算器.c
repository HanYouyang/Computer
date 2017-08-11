#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int num1, num2;
	char mark;
	cin >> num1 >> num2 >> mark;
	switch(mark){
		case '+': cout << num1 + num2; break;
		case '-': cout << num1 - num2; break;
		case '*': cout << num1 * num2; break;
		case '/': if(num2 == 0) cout << "Divided by zero!"; else cout << num1/num2; break;
		default : cout << "Invalid operator!";
	}
	return 0;
}