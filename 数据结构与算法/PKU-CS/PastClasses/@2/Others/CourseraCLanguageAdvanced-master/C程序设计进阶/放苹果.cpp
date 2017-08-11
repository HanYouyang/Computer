#include<iostream>
#include<stdlib.h>
using namespace std;
int f(int m, int n){
	if (m <= 1 || n <= 0) return 1;
	if (m < n){
		return f(m, m);
	}	
	else{
		return f(m, n - 1) + f(m - n, n);
	}		
}
int main(){
	cout << f(100, 100);
	system("pause");
	return 0;
}