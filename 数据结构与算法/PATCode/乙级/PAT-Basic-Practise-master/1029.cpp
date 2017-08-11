#include <stdio.h>
#include <string.h>
#include <ctype.h>
void insert(char s[], char a, char *x){
	for (int i=0; i<*x; i++)
        if (s[i] == a)  //字符已存在，直接退出 
            return;
    s[(*x)++] = a;
}
int main()
{
	int i, j;
	char str1[81]={0}, str2[81]={0}, res[81]={0}, x=0;
	scanf("%s %s", str1, str2);
	
	for(i=0,j=0; i<strlen(str1); i++){
			if(toupper(str1[i]) != toupper(str2[j])){
				insert(res, toupper(str1[i]), &x);
			}
			else{
				j++;
			}
	}
	
	printf("%s\n", res);
	return 0;
}
