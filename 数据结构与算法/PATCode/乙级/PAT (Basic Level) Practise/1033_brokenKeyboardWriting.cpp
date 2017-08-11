//2016年2月16日14时40分11秒
//2016年2月16日15时28分34秒

//题目保证第二行不为空，没有说第一行是否为空
//如果第一行为空，scanf直接读取第二行了，所以需要使用gets来读取输入

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	bool isBroke[128] = {false};
	char broke[200];
	//scanf("%s", broke);
	gets(broke);
	int lenb = strlen(broke);
	char text[100010];
	//scanf("%s", text);
	gets(text);
	/*if(0 == lenb){
		printf("%s\n", text);
		return 0;
	}*/
	int lent = strlen(text);
	
	for(int i = 0; i < lenb; i++){
		char c = broke[i];
		if(isalpha(c)) isBroke[c - 'A' + 'a'] = true;
		isBroke[c] = true;
	}
	if(isBroke['+']){
		for(int temp = 'A'; temp <= 'Z'; temp++)
			isBroke[temp] = true;
	}

	for(int i = 0; i < lent; i++){
		char temp = text[i];
		if(!isBroke[temp]){
			printf("%c", text[i]);
		}
	}
	printf("\n");
	return 0;
}
