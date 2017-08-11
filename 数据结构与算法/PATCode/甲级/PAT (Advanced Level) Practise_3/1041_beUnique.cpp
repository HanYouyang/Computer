//2016年2月16日18时42分28秒
//2016年2月16日18时58分30秒
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//maxn为10010时测试点4，5会出现断错误
const int maxn = 100010;

int main()
{
	int n;
	int num[maxn] = {0}, hashTable[maxn] = {0};
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	for(int i = 0; i < n; i++){
		hashTable[num[i]]++;
	}
	for(int i = 0; i < n; i++){
		if(hashTable[num[i]] == 1){
			cout << num[i];
			return 0;
		}
	}
	cout << "None";
	return 0;
}
