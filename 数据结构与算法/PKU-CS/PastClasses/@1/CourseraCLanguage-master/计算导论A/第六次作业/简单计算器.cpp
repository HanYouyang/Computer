#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int a, b,result; char c;
	cin >> a >> b; cin >> c;
	switch (c){
	case '+':
		result = a + b;
		cout << result << endl;
		break;
	case '-':
		result = a - b;
		cout << result << endl;
		break;
	case '*':
		result = a*b;
		cout << result << endl;
		break;
	case '/':
		if (b == 0){
			cout << "Divided by zero!" << endl;
		}
		else{
			result = a / b;
			cout << result << endl;
		}
		break;
	default:
		cout << "Invalid operator!" << endl;
	}
	system("pause");
	return 0;
}