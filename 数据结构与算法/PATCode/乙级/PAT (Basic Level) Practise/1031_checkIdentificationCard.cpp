//2016年2月7日10时58分07秒
//2016年2月7日11时58分50秒
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int map[11] = {1, 0, 'X'-'A', 9, 8, 7, 6, 5, 4, 3, 2};
int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

bool isTrue(string str){
	int sum = 0, Z;
	for(int i = 0; i < 17; i++){
		if(!isdigit(str[i])) return false;
		sum += (str[i] - '0') * weight[i];
		//char型数字(0-9)*int想要达到数字(0-9)*int的效果需要
		//使用(char-'0') * int
	}
	Z = sum % 11;
	if(Z != 2){
		if(map[Z] != str[17] - '0') return false;
		//char型数字(0-9)与int型数字比较，仍然需要
		//使用char - '0'
	}
	else{
		if(str[17] != map[Z] + 'A') return false;
	}
	return true;
}

int main()
{
	int n;
	string str;
	bool allTrue = true;
	cin >> n;
	while(n--){
		cin >> str;
		if(!isTrue(str)){
			cout << str << endl;
			allTrue = false;
		}
	}
	if(allTrue)
		cout << "All passed" << endl;
	return 0;	
}

