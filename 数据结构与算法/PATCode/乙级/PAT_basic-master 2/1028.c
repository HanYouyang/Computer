#include<stdio.h>
typedef struct {
	char name[6];
	int year;
	int month;
	int day;
}sample;
int who_is_older(sample a,sample b);/*比较2条录入信息年龄的大小*/
int main()
{
	int n,i,cnt=0;
	sample youngest={"a",2014,9,6},oldest={"b",1814,9,6},old={"a",2014,9,6},young={"b",1814,9,6},A;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d/%d/%d",A.name,&A.year,&A.month,&A.day);
		if(who_is_older(A,youngest)&&who_is_older(oldest,A))
		{
			if(who_is_older(young,A))
			{
				young=A;
			}
			if(who_is_older(A,old))
			{
				old=A;
			}
			cnt++; 
		}
	}
	if(cnt>0)
	{
		printf("%d %s %s\n",cnt,old.name,young.name);
	}else
	{
		printf("0");
	}
	
	
	
	
	return 0;
}
int who_is_older(sample a,sample b)
{
	if(((a.year)*1000+(a.month)*100+(a.day))>((b.year)*1000+(b.month)*100+(b.day)))
	{
		return 0;
	}else
	{
		return 1;
	}
}
