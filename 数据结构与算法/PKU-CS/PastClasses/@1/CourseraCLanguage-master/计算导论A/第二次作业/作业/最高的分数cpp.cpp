#include<iostream>
using namespace std;
int main(){
	int n, num[100];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	int max = num[0];
	for (int i = 1; i < n; i++){
		if (max < num[i]){
			max = num[i];
		}
	}
	cout << max;
	return 0;
}