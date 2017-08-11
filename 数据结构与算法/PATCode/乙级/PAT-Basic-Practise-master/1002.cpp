#include <stdio.h>
#include <string.h>
#define MAX 105
void fenjie(int num);
char s[MAX];
char str[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
int flag = 1;
int main()
{
	int i, sum=0;
	scanf("%s",s);
	for(i=0; i<strlen(s); i++){
		sum += (s[i]-'0');
	}
	if(sum > 0){
		fenjie(sum);
	} else {
		printf("ling");
	}
	printf("\n");
	return 0;
}
void fenjie(int num)
{
	int k;
	if( num != 0 ){
		k = num % 10;
		num = num/10;
		fenjie(num);
		if(flag){
			flag=0;
		} else {
			printf(" ");
		}
		printf("%s", str[k]);
	}
}
