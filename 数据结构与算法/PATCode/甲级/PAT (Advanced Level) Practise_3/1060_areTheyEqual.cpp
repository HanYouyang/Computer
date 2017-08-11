//2016年2月24日21时56分40秒
//2016年2月24日23时35分16秒

//本题注意点比较多有如下易错数据
//4 0000 0000.00
//4 00123.5678 0001235
//3 0.0520 0.0521
//3 0.000 0
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string process(string str, int & expTemp, int n)
{
	while(str[0] == '0') str.erase(str.begin());
	//开头为零要删除
	if(str.find(".") != string::npos){
	//将小数点删除并存储相应科学计数法的指数位数expTemp
		expTemp = str.find(".");
		str.erase(str.begin() + expTemp);
	} else {
		expTemp = str.length();
	}
	while(str[0] == '0'){
	//继续删除零（小数点在开头并且小数点后有零）
		str.erase(str.begin());
		expTemp--;//每去掉一个零，指数减1
	}
	if(str.size() == 0) expTemp = 0;
	//如果删除开头的零和小数点后str为空串，那么str代表的数为0，因此expTemp为0
	int len = str.length();
	//处理后的字符串的长度
	if(n == len){//有效位等于长度，直接输出
		return str;
	} else if(n > len){//有效位大于长度，在str末尾补零
		int less = n - len;
		while(less--){
			str.insert(str.end(), '0');
		}
		return str;
	} else {//有效位小于长度，删除str的末尾
		int more = len - n;
		while(more--){
			str.erase(str.end() - 1);
		}
		return str;
	}
}

int main()
{
	int n, expa, expb;//有效位数，a的实际指数，b的实际指数
	string stra, strb;//字符串a，字符串b
	cin >> n >> stra >> strb;//input
	stra = process(stra, expa, n);//对字符串a进行处理
	strb = process(strb, expb, n);
	if(stra == strb && expa == expb){
	//如果处理后的字符串相等并且实际指数相等，输出YES
		cout << "YES";
		cout << " 0." << stra << "*10^" << expa;
	} else {//否则，输出NO
		cout << "NO";
		cout << " 0." << stra << "*10^" << expa;
		cout << " 0." << strb << "*10^" << expb;
	}
	return 0;
}

