#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct list
{
	char ID[15];
	int examNumber;
}student;
int main()
{
	int N,M,tempExamNumber,testNumber,i;
	char tempID[15];
	scanf("%d",&N);
	student *allList=malloc(N*sizeof(student));
	for(i=0;i<N;i++)
	{
		scanf("%14s %d %d",tempID,&testNumber,&tempExamNumber);
		strcpy(allList[testNumber].ID,tempID);
		allList[testNumber].examNumber=tempExamNumber;
	}
	scanf("%d",&M);
	for(i=0;i<M;i++)
	{
		scanf("%d",&testNumber);
		printf("%s %d\n",allList[testNumber].ID,allList[testNumber].examNumber);
	}
	
	return 0;
}
