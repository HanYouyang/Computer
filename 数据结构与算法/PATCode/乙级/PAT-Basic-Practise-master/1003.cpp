#include <stdio.h>
#include <string.h>
#define MAX 105
char str[MAX];
int main()
{
	int i, j, n;
	char str[MAX];
	scanf("%d",&n);
	
	int a, b, c;
	
	for(i=0; i<n; i++){
		scanf("%s",str);
		
		if(strlen(str) < 3){
			printf("NO\n");
			continue;
		}
		for(j=0,a=0; str[j]=='A'; j++){
			a++; //统计P前面A的个数 
		}
		if(str[j] == 'P'){
			j++;
			for(b=0; str[j]=='A'; j++){
				b++; //统计P后面A的个数
			}
			if(b == 0){
				//P后面没有A
				printf("NO\n");
				continue;
			}
			if(str[j] == 'T'){
				j++;
				for(c=0; str[j]=='A'; j++){
					c++; //统计T后面A的个数
				}
				if(str[j]=='\0' && c==(a*b)){
					printf("YES\n");
					continue;
				} else {
					printf("NO\n");
					continue;
				}
			} else {
				printf("NO\n");
				continue;
			}
		} else {
			printf("NO\n");
			continue;
		}	
	}
	return 0;
}
