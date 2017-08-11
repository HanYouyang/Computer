#include<stdio.h>
int main()
{
	const double CLK_TCK=100.0;
	int h=0,m=0,s=0;
	int c1,c2,time;
	double c1c2;
	scanf("%d %d",&c1,&c2);
	c1c2=(c2-c1)/CLK_TCK;
	time=(int)c1c2;
	if(c1c2-time>=0.5)
	{
		time+=1;
	}
	s=time%60;
	time/=60;
	m=time%60;
	h=time/60;
	printf("%02d:%02d:%02d",h,m,s);
	
	return 0;
} 
