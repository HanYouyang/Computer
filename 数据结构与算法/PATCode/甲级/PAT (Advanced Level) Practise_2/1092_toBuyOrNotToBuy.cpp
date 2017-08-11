//2016年2月16日15时44分50秒
//2016年2月16日16时03分24秒
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int hashFunc(char c){
	if(isdigit(c)) return c - '0';
	else if(islower(c)) return c - 'a' + 10;
	else return c - 'A' + 10 + 26;
}

int main()
{
	int hashTable[62] = {0};
	int less = 0;//缺了几个
	char whole[1010], target[1010];
	gets(whole);
	gets(target);
	int lenw = strlen(whole);
	int lent = strlen(target);
	for(int i = 0; i < lenw; i++){
		int temp = hashFunc(whole[i]);
		hashTable[temp]++;
	}
	for(int i = 0; i < lent; i++){
		int temp = hashFunc(target[i]);
		hashTable[temp]--;
		if(hashTable[temp] < 0) less++;
	}
	if(less > 0){
		printf("No %d", less);
	} else {
		printf("Yes %d", lenw - lent);
	}
	return 0;
}
