#include <iostream>
#include <string>
using namespace std;
bool feifa(string s){
	int QZ[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	int sum = 0;
	for(int i=0; i<17; i++){
		if(s[i] < '0' || s[i] > '9')
			return true;
		sum += ((s[i]-'0')*QZ[i]);
	}
	if(M[sum%11] == s[17])
		return false;
	else 
		return true;
}
int main()
{
	int n;
	cin >> n;
	bool flag = true;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		if(feifa(s)){
			cout << s << endl;
			flag = false;
		}
		if((i == n-1) && flag){
			cout << "All passed" << endl;
		}
	}
	return 0;
}
