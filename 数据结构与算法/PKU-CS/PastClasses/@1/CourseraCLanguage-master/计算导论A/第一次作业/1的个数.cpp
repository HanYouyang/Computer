#include<iostream>
using namespace std;
#include<stdlib.h>
int main4(){
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
	system("pause");
	return 0;
}