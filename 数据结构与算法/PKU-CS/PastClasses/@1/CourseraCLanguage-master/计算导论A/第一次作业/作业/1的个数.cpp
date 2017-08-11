#include<iostream>
using namespace std;
int main(){
	int n,num[100];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	int count;
	for (int i = 0; i < n; i++){
		count = 0;
		while (num[i] != 0){
			if (num[i] % 2 == 1){
				count++;
			}
			num[i] /= 2;
		}
		cout << count << endl;
	}
	return 0;
}