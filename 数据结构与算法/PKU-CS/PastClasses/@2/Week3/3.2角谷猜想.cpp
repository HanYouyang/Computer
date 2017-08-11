#include <iostream>
using namespace std;

void count(int n){
	if (n == 1) {
		cout << "End" << endl;
		return;
	}
	if (n % 2 == 0){
		cout << n << "/" << 2 << "=" << n / 2 << endl;
		count(n / 2);
	}
	else{
		cout << n << "*3+1=" << (n * 3 + 1) << endl;
		count(3 * n + 1);
	}
}
int main(){
	int n; cin >> n;
	count(n);
	
	return 0;
}