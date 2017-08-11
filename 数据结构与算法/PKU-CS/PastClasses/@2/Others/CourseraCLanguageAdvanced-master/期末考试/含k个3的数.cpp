#include<iostream>
#include<stdlib.h>
using namespace std;
int main1(){
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
	system("pause");
	return 0;
}