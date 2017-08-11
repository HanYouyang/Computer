#include <stdio.h>
int main()
{
	int i, j;
	int str[10];
	for(i=0; i<10; i++)
		scanf("%d", &str[i]);
	for(i=1; i<10; i++)
		if(str[i] != 0){
			printf("%d", i);
			str[i]--;
			break;
		}
	for(i=0; i<10; i++)
		if(str[i] != 0){
			for(j=str[i]; j>0; j--)
				printf("%d", i);
		}
	printf("\n");
	return 0;
}
