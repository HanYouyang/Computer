//2016年2月16日13时47分57秒
//2016年2月16日14时31分49秒
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int hashFunc(char s){
	if(isdigit(s)) return (s - '0' + 26);
	else if(isalpha(s)) return (toupper(s) - 'A');
	else return 36;
}

int main()
{
	bool isBroke[37] = {0};
	char original[85];
	scanf("%s", original);
	int leno = strlen(original);
	char typedout[85];
	scanf("%s", typedout);
	int lent = strlen(typedout);
	int index = 0;
	for(int i = 0; i < lent; i++){
		for(int j = index; j < leno; j++){
			if(original[j] == typedout[i]){
				index = j + 1;
				break;
			}
			else{
			int temp = hashFunc(original[j]);
				if(!isBroke[temp]){
					isBroke[temp] = true;
					if(islower(original[j])) printf("%c", toupper(original[j]));
					else printf("%c", original[j]);
				}
			}
		}
	}
	while(index < leno){
		int j = index;
		int temp = hashFunc(original[j]);
		if(!isBroke[temp]){
			isBroke[temp] = true;
			if(islower(original[j])) printf("%c", toupper(original[j]));
			else printf("%c", original[j]);
		}
		index++;		
	}
	return 0;
}
