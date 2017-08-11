#include<iostream>
#include<stdlib.h>
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
	//需要健壮性的判断
	if (reduce <= 10){
		cout << (n - reduce);
	}
	else{
		cout << 0;
	}
	
	system("pause");
	return 0;
}