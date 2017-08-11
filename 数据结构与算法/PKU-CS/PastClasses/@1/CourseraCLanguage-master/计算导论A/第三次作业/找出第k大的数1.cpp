#include<iostream>
#include<stdlib.h>
using namespace std;
int partition(int* a, int low, int high){
	int temp = a[low];
	while (low<high){
		while (low<high&&a[high]>temp)
			high--;
		a[low] = a[high];
		while (low<high&&a[low]<temp)
			low++;
		a[high] = a[low];
	}
	a[low] = temp;
	return low;
}
int getMin_i(int* a, int low, int high, int i_min){
	int p = partition(a, low, high);
	if (i_min == p - low + 1)
		return a[p];
	if (i_min<p - low + 1)
		return getMin_i(a, low, p - 1, i_min);
	else
		return getMin_i(a, p + 1, high, i_min - (p - low + 1));
}
int main(){
	int n, k,num[100];
	cin >> n; cin >> k;
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	for (int i = 0; i < n; i++){
		cout << "---" << num[i];
	}
	cout << endl;
	cout << getMin_i(num, 0, n - 1, n-k+1);
	system("pause");
	return 0;
} 