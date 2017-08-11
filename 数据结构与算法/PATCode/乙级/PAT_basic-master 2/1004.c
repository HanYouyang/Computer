#include<stdio.h>
#include<string.h>

struct student
{
	char name[20];
	char number[20];
	int  score;
};

int main()
{
	int n=0,i;
	struct student input,first,last;
	input =(struct student){"a","b",0};
	first =(struct student){"a","b",0};
	last = (struct student){"a","b",100};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s %s %d",&input.name,&input.number,&input.score);
		if(input.score>=first.score)
		{
			first=input;
		}
		if(input.score<=last.score)
		{
			last=input;
		}
	}
	printf ("%s %s\n",first.name,first.number);
	printf ("%s %s\n",last.name,last.number);	
	
	
	return 0;
}
