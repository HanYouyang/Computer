//2016年1月31日13时17分01秒
//2016年1月31日13时46分56秒

//找到“两侧字符数总是取(n+2)/3”这个规律很关键

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, row, column = 3;
	string s;
	cin >> s;
	n = s.length();
	row = (n + 2) / 3;
	column = n + 2 - 2 * row;
	for(int i = 0; i < (row - 1); i++){
		cout << s[i];
		for(int j = 0; j < (column - 2); j++)
			cout << ' ';
		cout << s[n-1-i] << endl;
	}
	for(int i = 0; i < column; i++)
		cout << s[row - 1 + i];
	return 0;
}
