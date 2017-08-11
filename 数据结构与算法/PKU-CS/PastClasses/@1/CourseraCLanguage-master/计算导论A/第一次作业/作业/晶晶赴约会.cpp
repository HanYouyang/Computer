#include<iostream>
using namespace std;
int main(){
	int day;
	cin >> day;
	if (day == 1 || day == 3 || day == 5){
		cout << "NO";
	}
	else{
		cout << "YES";
	}
	return 0;
}