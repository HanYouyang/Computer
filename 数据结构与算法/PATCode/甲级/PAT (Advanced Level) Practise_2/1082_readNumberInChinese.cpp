//2016年2月12日18时32分56秒
//2016年2月12日19时42分45秒
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string num[10] = {
	"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};

string wei[5] = {
	"Shi", "Bai", "Qian", "Wan", "Yi"
};

int main()
{
	string integer;
	cin >> integer;
	int len = integer.length();
	int left = 0, right = len - 1;
	if('-' == integer[0]) { cout << "Fu"; left++; }
	while(left + 4 <= right) { right -= 4; }
	while(left < len) {
		bool cumulateZero = false;
		bool isPrint = false;
		while(left <= right) {
			if(left > 0 && '0' == integer[left]) { cumulateZero = true; }
			else {
				if(cumulateZero == true) { cout << " ling"; cumulateZero = false; }
				if(left > 0) cout << ' ';
				cout << num[integer[left] - '0'];
				isPrint = true;
				if(left != right){ cout << ' ' << wei[right - left - 1]; }
				
			}
			left++;
		}
		if(isPrint == true && right != len - 1)
			cout << ' ' << wei[(len - 1 - right) / 4 + 2];
		right += 4;
	}
	return 0;
}
