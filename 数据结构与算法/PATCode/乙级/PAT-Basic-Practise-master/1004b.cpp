#include <stdio.h>
#include <string.h>
int main()
{
	char name[11], maxname[11], minname[11];
	char number[11], maxnum[11], minnum[11];
	int grade, max=-1, min=101;
	
	int i, n;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s %s %d", name, number, &grade);
		if(max < grade){
			max = grade;
			strcpy(maxname, name);
			strcpy(maxnum, number);
		}
		if(min > grade){
			min = grade;
			strcpy(minname, name);
			strcpy(minnum, number);
		}
		
	}
	printf("%s %s\n%s %s\n",maxname, maxnum, minname, minnum);
	return 0;
}
