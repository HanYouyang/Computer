#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int n,bit; cin >> n;
	for (int i = 10; i <= n; i++){
		bit = i / 10 + i % 10;
		if (i%bit == 0){
			cout << i << endl;
		}
	}
	system("pause");
	return 0;
}