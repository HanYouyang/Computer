//2016年2月7日13时37分25秒
//2016年2月7日17时29分16秒
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int len = str.length();
	//validBit是小数位数; exp是指数大小
	int i = 0, validBit = 0, exp = 0;
	//如果指数是负数 那么expIsNegtive为true;
	bool expIsNegtive = false;
	if(str[0] == '-') cout << '-' ;
	//求小数为数
	for(i = 3; str[i] != 'E'; i++) validBit++;
	//判断指数是否为负数
	if(str[++i] == '-') expIsNegtive = true;
	//求指数大小
	for(i++; i < len; i++) exp = (exp * 10) + (str[i] - '0');
	//指数为正数与负数时的不同输出方式
	if(expIsNegtive){
		for(int i = 0; i < exp; i++){
			cout << '0';
			if(!i) cout << '.';
		}
		cout << str[1];
		for(int i = 0; i < validBit; i++) cout << str[i+3];
	}
	else{
		int i = 0;
		bool first = true;
		cout << str[1];
		for(i = 0; i < validBit && i < exp; i++) cout << str[i+3];
		while(i < exp){
			cout << '0' ;
			i++;
		}
		while(i < validBit){
			if(first){
				first = false;
				cout << '.' ;
			}
			cout << str[i+3];
			i++;
		}
	}
	return 0;
}
