#include<iostream>
using namespace std;
int main(){
	int n, num[100];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	int low = 0,high=n-1;
	while (low < high){
		int temp = num[low];
		num[low] = num[high];
		num[high] = temp;
		low++; high--;
	}
	for (int i = 0; i < n; i++){
		if (i == n - 1){
			cout << num[i];
		}
		else{
			cout << num[i] << " ";
		}
	}
	return 0;
}