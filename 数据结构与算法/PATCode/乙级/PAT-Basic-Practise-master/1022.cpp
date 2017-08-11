#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int a, b, d;
	cin >> a >> b >> d;
	int sum = a + b;
	stack<int> stk;
	
	do{
		stk.push(sum % d);
		sum /= d;
	} while(sum != 0);
	while(!stk.empty()){
		cout << stk.top();
		stk.pop();
	}
	cout << endl;
	return 0;	
}
