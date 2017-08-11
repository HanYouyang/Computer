#include<iostream>
#include<stdlib.h>
using namespace std;
int main2(){
	int n,num[100],walk,bike;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	for (int i = 0; i < n; i++){
		walk = (int)(num[i] / 1.2) + 1;
		bike = 50 + (num[i] % 3 == 0 ? num[i] / 3 : (num[i] / 3 + 1));
		if (bike < walk){
			cout << "Bike" << endl;
		}
		else if (bike>walk){
			cout << "Walk" << endl;
		}
		else{
			cout << "All" << endl;
		}
	}
	system("pause");
	return 0;
}