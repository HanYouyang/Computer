//2016年2月20日17时59分20秒
//2016年2月20日18时14分39秒
//思路：令初始PAT的个数为count = 0；先遍历一遍字符串，求出字符'T'的个数tright;并令初始P的个数为pleft = 0;
//然后遍历字符串，遇到'P'则pleft++；遇到'T'则tright--；遇到'A'则count += pleft * tright；
#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
	cin >> str;
	int len = str.length();
	int pleft = 0;//
	int tright = 0;
	long long count = 0;
	for(string::iterator it = str.begin(); it != str.end(); it++){
		if(*it == 'T') tright++;
	}
	for(string::iterator it = str.begin(); it != str.end(); it++){
		if(*it == 'A'){
			count += pleft * tright;
			count %= 1000000007;
		} else if(*it == 'P') pleft++;
		else tright--;
	}
	cout << count;
	return 0;
}
