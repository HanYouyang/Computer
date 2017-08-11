#include<iostream>
#include<stdlib.h>
using namespace std;
int main2(){
	int n;
	while (cin >> n){
		if (n % 3 == 0){
			cout << 3 << " ";
		}
		if (n % 5 == 0){
			cout << 5 << " ";
		}
		if (n % 7 == 0){
			cout << 7 << " ";
		}
		if (n % 3 != 0 && n % 5 != 0 && n % 7 != 0){
			cout << 'n' << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}