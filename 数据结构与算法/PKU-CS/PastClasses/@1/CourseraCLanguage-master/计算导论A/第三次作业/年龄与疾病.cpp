#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int main2(){
	int n, num[100],a=0,b=0,c=0,d=0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	for (int i = 0; i < n; i++){

		if (num[i] >= 1 && num[i] <= 18){
			a++;
		}
		if (num[i] >= 19 && num[i] <= 35){
			b++;
		}
		if (num[i] >= 36 && num[i] <= 60){
			c++;
		}
		if (num[i]>60){
			d++;
		}
	}
	cout << "1-18: " << setiosflags(ios::fixed) << setprecision(2) << (a*100.0 / n)<<"%" << endl;
	cout << "19-35: " << setiosflags(ios::fixed) << setprecision(2) << (b*100.0 / n) << "%" << endl;
	cout << "36-60: " << setiosflags(ios::fixed) << setprecision(2) << (c*100.0 / n) << "%" << endl;
	cout << "60-: " << setiosflags(ios::fixed) << setprecision(2) << (d*100.0 / n) << "%" << endl;
	system("pause");
	return 0;
}