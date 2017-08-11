//2016年2月16日18时06分26秒
//2016年2月16日18时21分25秒
#include <iostream>
#include <cstdio>
#include <cstring>

const int maxn = 10010;

using namespace std;

int main()
{
	int hashTable[6] = {0};
	char map[7] = {'P', 'A', 'T', 'e', 's', 't'};
	char str[maxn];
	gets(str);
	int len = strlen(str);
	int validNum = 0;
	for(int i = 0; i < len; i++){
		char temp = str[i];
		switch(temp){
			case 'P':
				hashTable[0]++; validNum++; break;
			case 'A':
				hashTable[1]++; validNum++; break;
			case 'T':
				hashTable[2]++; validNum++; break;
			case 'e':
				hashTable[3]++; validNum++; break;
			case 's':
				hashTable[4]++; validNum++; break;
			case 't':
				hashTable[5]++; validNum++; break;
			default:
				break;
		}
	}
	while(validNum){
		for(int i = 0; i < 6; i++){
			if(hashTable[i]){
				validNum--;hashTable[i]--;
				printf("%c", map[i]);
			}
		}
	}
	return 0;

}
