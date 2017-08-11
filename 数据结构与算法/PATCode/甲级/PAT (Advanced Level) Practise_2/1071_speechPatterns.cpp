//2016年2月25日14时43分00秒
//2016年2月25日15时57分33秒
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
map<string, int> mp;
//判断是否是字符或字母可以使用cstdio头文件中的isalpha(char) isdigit(char) 在1000000个字符的情况下不会超过300ms（亲测）
//bool check(char c)
//{//字符c如果时字母或者数字，返回true；否则返回false
//	if(c >= 'a' && c <= 'z') return true;
//	else if (c >= 'A' && c <= 'Z') return true;
//	else if (c >= '0' && c <= '9') return true;
//	return false;
//}

int main()
{
	string str;
	getline(cin, str);
	int i = 0;
	while(i < str.length()){
		string word;//存储单词
		while(i < str.length() && (isalpha(str[i]) || isdigit(str[i]))){
		//while(i < str.length() && check(str[i]) == true){
			if(isupper(str[i])) word += tolower(str[i]);//如果时大写，改为小写并加到word后
			else word += str[i];//直接加到word后
			//if(str[i] >= 'A' && str[i] <= 'Z'){
			//	str[i] += 32;
			//}
			//word += str[i];
			i++;
		}
		if(word != ""){//如果不是空子符串，对其作映射
			if(mp.find(word) == mp.end()) mp[word] = 1;
			else mp[word]++;
		}
		while(i < str.length() && !isalpha(str[i]) && !isdigit(str[i])){
		//while(i < str.length() && check(str[i]) == false){
		////略过不是字母和数字的字符
			i++;
		}
	}
	string maxLetter;//出现最多的单词
	int maxNum = 0;//出现的次数
	for(map<string,int>::iterator it = mp.begin(); it != mp.end(); it++){
		if(it->second > maxNum){//有更多次数的单词出现则更新
			maxLetter = it->first;
			maxNum = it->second;
		} else if(it->second == maxNum){//两单词出现次数相等
			if(it->first < maxLetter){//选择字典序小的
				maxLetter = it->first;
				maxNum = it->second;
			}
		}
	}
	cout << maxLetter << ' ' << maxNum << endl;//输出
	return 0;
}
//下面的俄核心代码是有问题的 测试点0正确；1，4异常退出；2，3运行超时
//通过上面的测试，不是isalpha(char) isdigit(char) tolower(char) 这些函数的问题
//那么可能是一直对string执行erase和find操作比较费时间*********************************important*************************
	//while(str.size() != 0){
	//	int len = 0;
	//	for(int i = 0; isalpha(str[i]) || isdigit(str[i]); i++){
	//		len++;
	//		if(isalpha(str[i])) str[i] = tolower(str[i]);
	//	}
	//	string letter = str.substr(0, len);
	//	if(mp.find(letter) == mp.end()) {
	//		mp[letter] = 1;
	//	} else {
	//		mp[letter]++;
	//	}
	//	str.erase(str.begin(), str.begin() + len);
	//	while(str.size() > 0 && !isalpha(str[0]) && !isdigit(str[0])) str.erase(str.begin());
	//}
