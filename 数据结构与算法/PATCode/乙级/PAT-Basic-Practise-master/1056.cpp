#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int sum = 0;
	for(int i = 0; i < n; i++)
		for(int j =0; j < n; j++){
			if(j != i){
				sum += (a[i] * 10 + a[j]);
			}
		}
	cout << sum << endl;
	return 0;
}
