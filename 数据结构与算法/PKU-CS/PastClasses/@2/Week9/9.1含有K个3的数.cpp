#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int m, k, single, count = 0; cin >> m; cin >> k; int temp = m;
	while (m != 0){
		single = m % 10;
		if (single == 3){
			count++;
		}
		m /= 10;
	}
	if (temp % 19 == 0 && count == k){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	
	return 0;
}