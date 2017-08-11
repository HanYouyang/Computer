//2016年2月19日13时34分50秒
//2016年2月19日19时05分32
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const long long maxradix = (1LL << 52) - 1;

//long long str2decimal(string str, long long radix)
//{
//	if(str.length() == 0) return 0;
//	else {
//		char temp = str[0];
//		str.erase(str.begin());
//		long long mult = 1;
//		for(int i = 0; i < str.length(); i++) mult *= radix;
//		if(isdigit(temp)) return (temp - '0') * mult + str2decimal(str, radix);
//		else return (temp - 'a' + 10) * mult + str2decimal(str, radix);
//	}
//}

long long str2decimal(char *str, long long radix)
{
	long long ans = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		ans *= radix;
		if(isdigit(str[i])) ans += str[i] - '0';
		else ans += str[i] - 'a' + 10;
		if(ans < 0) return -1;
	}
	return ans;
}

int main()
{
	char str[2][15];
	int tag;
	long long radix;
	bool flag = false;
	scanf("%s%s%d%lld", str[0], str[1], &tag, &radix);
	long long num1 = str2decimal(str[tag - 1], radix);
	long long radixl = 2;
	int len = strlen(str[!(tag - 1)]);
	for(int i = 0; i < len; i++){
		int tempNum;
		if(isdigit(str[!(tag - 1)][i])) tempNum = str[!(tag - 1)][i] - '0' + 1;
		else tempNum = str[!(tag - 1)][i] - 'a' + 10 + 1;
		if(tempNum > radixl) radixl = tempNum;
	}
	long long radixr =  max(radixl, num1 + 1), mid, num2;
	while(radixl <= radixr){
		//写成radixr / 2 + radixl / 2会导致测试点1错误
		mid = (radixr + radixl) / 2;
		num2 = str2decimal(str[!(tag - 1)], mid);
		if (num2 == -1 || num2 > num1) {
			radixr = mid - 1;
			//radixr = mid;是错误的，会导致无法退出循环
		} else if (num2 < num1){
			radixl = mid + 1;
		} else {
			flag = true;
			break;
		}
	}
	if(flag) cout << mid << endl;
	else  cout << "Impossible" << endl;
	return 0;

