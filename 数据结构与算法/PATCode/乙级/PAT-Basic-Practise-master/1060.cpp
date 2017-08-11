#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	int E = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] > n-i){
			E = n - i;
			break;
		}
	}
	cout << E << endl;
	return 0;
}
