#include<iostream>
using namespace std;
int main(){
	int m, n,result=0;
	cin>>m;
	cin >> n;
	for (int i = m; i <= n; i++){
		if (i % 2 == 1){
			result += i;
		}
	}
	cout << result;
	return 0;
}