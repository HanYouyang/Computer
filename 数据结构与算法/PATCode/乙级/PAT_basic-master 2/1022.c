#include<stdio.h> 
#include<string.h>
int main()
{
	int A,B,D,sum=0,i=0,j=0;
	int number[100]={};/*转换成2进制最多可能有32位，所以给个100的数组足够*/
	scanf("%d %d %d",&A,&B,&D);
	sum=A+B;
	
	while(sum!=0)
	{
		number[i]=sum%D;
		sum=sum/D;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
		printf("%d",number[j]);
	}
	if(i==0)/*没有进入过循环，即A+B=0*/ 
	{
		printf("0");
	}
	

	
	return 0;
}
