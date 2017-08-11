//2016年2月11日15时06分24秒
//2016年2月11日15时45分03秒
#include <cstdio>
#include <cstring>

char num[10][10] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};
char s[111];
//int digit[10];

void dfs(int n)
{
	if(n / 10 == 0){
		printf("%s", num[n % 10]);
		return;
	}
	dfs(n / 10);
	printf(" %s", num[n % 10]);
}

int main()
{
	gets(s);
	int len = strlen(s);
	int sum = 0, numLen = 0;
	for(int i = 0; i < len; i++){
		sum += (s[i] - '0');
	}
	//sprintf(digit, %d, sum);
	dfs(sum);
	return 0;
}
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//string map[11] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
//
//int main()
//{
//	string str;
//	cin >> str;
//	int sum = 0;
//	for(string::iterator it = str.begin(); it != str.end(); it++){
//		sum += *it - '0';
//	}
//	int len = 0, num[10] = {0};
//	if(!sum) num[len++] = 0;
//	while(sum){
//		num[len++] = sum % 10;
//		sum /= 10;
//	}
//	cout << map[num[--len]];
//	for(len--; len >=0; len--){
//		cout << ' ' << map[num[len]];
//	}
//	return 0;
//}
