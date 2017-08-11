//2016年2月16日17时42分37秒
//2016年2月16日
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int count[26] = {0};
	char str[1010];
	gets(str);
	int len = strlen(str);
	int mark[26];
	for(int i = 0; i < 26; i++) mark[i] = i;
	for(int i = 0; i < len; i++){
		if(isalpha(str[i])) count[tolower(str[i]) - 'a']++;
	}
	int max = 0;
	for(int i = 0; i < 26; i++){
		if(count[i] > count[max]) max = i;
	}
	printf("%c %d\n", max + 'a', count[max]);
	return 0;
}
