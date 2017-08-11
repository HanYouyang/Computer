#include<stdio.h>
int main()
{
	int g1,s1,k1,g2,s2,k2;
	int sum1=0,sum2=0;
	scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
	sum1=g1*17*29+s1*29+k1;
	sum2=g2*17*29+s2*29+k2;
	sum2=sum2-sum1;
	if(sum2<0)
	{
		sum2*=-1;
		printf("-%d.%d.%d",sum2/29/17,sum2/29%17,sum2%29);	
	}else
	{
		printf("%d.%d.%d",sum2/29/17,sum2/29%17,sum2%29);
	}

	return 0;
}
