#include<iostream>
using namespace std;
int main(){
	int n, x, y;
	cin >> n;
	cin >> x;
	cin >> y;
	int reduce = 0;
	if (y%x == 0){
		reduce = y / x;
	}
	else{
		reduce = y / x + 1;
	}
	cout << (n - reduce);
	return 0;
}