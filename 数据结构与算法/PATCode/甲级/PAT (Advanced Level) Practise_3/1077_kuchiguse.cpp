//2016年2月12日17时37分37秒
//2016年2月12日17时56分28秒
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n; cin >> n;
	string str[110];
	int minLen = 256, sameNum = 0;
	cin.get();
	for(int i = 0; i < n; i++){
		getline(cin, str[i]);
		reverse(str[i].begin(), str[i].end());
		if(str[i].length() < minLen) minLen = str[i].length();
	}
	for(int i = 0; i < minLen; i++){
		char c = str[0][i];
		bool same = true;
		for(int j = 1; j < n; j++){
			if(c != str[j][i]){
				same = false;
				break;
			}
		}
		if(same) sameNum++;
		else break;
	}
	if(sameNum){
		for(int i = sameNum - 1; i >= 0; i--)
			cout << str[0][i];
	}
	else{
		cout << "nai";
	}
	return 0;
}
