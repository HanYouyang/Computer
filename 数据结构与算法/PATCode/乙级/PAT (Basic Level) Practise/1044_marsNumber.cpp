//2016年2月25日09时33分08秒
//2016年2月25日13时55分50秒
//测试点2和4格式错误
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

string bitDigit[14] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[14] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string int2str;//数字->火星文
map<string, int> str2int;//火星文->数字

void toMars(string str)
{//将数字改成火星文
	int num = atoi(str.c_str());//将string改成数字
	int low = num % 13;//低位
	int high = num / 13;//高位
	if(high != 0){//高位不为零
		cout << tenDigit[high - 1];
		if(low != 0){//高位不为零的情况下低位不为零
			cout << ' ' << bitDigit[low] << endl;
		} else {//高位不为零，低位为零，不输出低位的零
			cout << endl;
		}
	} else {//高位为零，输出低位（零也输出）
		cout << bitDigit[low] << endl;
	}
}

void toEarth(string str)
{//将火星文改为数字
	int number = 0;//存储数字
	int pos = str.find(" ");//找到空格符
	if(pos == string::npos){//如果没有空格符，说明就一位
		number = str2int[str];
	} else {//有空格符，说明有两位
		string ten = str.substr(0, pos);
		number += str2int[ten];
		string bit = str.substr(pos + 1, str.length() - pos - 1);
		number += str2int[bit];
	}
	cout << number << endl;
}

int main()
{
	for(int i = 0; i < 13; i++){
		str2int[bitDigit[i]] = i;
	}//初始化map，将个位数的火星文映射到数字
	for(int i = 1; i < 13; i++){
		str2int[tenDigit[i - 1]] = i * 13;
	}//初始化map，将十位数的火星文映射到数字，已乘以13
	int n;//待转换的个数
	cin >> n;
	cin.get();//cin与getline相邻，要吸收掉换行符
	for(int i = 0; i < n; i++){
		string temp;//字符串
		getline(cin, temp);
		if(isdigit(temp[0])){//是数字
			toMars(temp);//转换成火星文
		} else {//是火星文
			toEarth(temp);//转换成数字
		}
	}
	return 0;
}
