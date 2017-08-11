#include<stdio.h>
int main()
{
	int N,i,j=1,sum=0,cnt=0,flag=0;
	int Number[1001]={0};
	double A[6]={0};
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&Number[i]);
	}
	for(i=0;i<N;i++)
	{
		switch(Number[i]%5)
		{
			case 0: 
				if(Number[i]%2==0)
				{
					A[1]+=Number[i];
				}	
				break;
			case 1: 
				A[2]+=j*Number[i];/*A[2]=0不一定就要输出N，要加入一个flag记录*/ 
				j*=-1;
				flag++; 
				break;
			case 2:
				A[3]++;
				break;
			case 3:
				sum+=Number[i];
				cnt++;
				break;
			case 4:
				if(Number[i]>A[5]){
					A[5]=Number[i];
				}
				break;
			
		}
	}
	if(cnt!=0)/*此处不加判断容易出错*/
	{
		A[4]=sum/(double)cnt;
	}
	
	for(i=1;i<6;i++)
	{
		if(i==2)
		{
			if(flag==0)
			{
				printf("N");
			}else
			{
				printf("%d",(int)(A[i]));	
			}
		}else if(i==4)
		{
			if(A[i]==0)
			{
				printf("N");
			}else
			{
				printf("%0.1f",A[i]);	
			}
		}else
		{
			if(A[i]==0)
			{
				printf("N");
			}else
			{
				printf("%d",(int)(A[i]));
			}
		}
		if(i!=5)
		{
			printf(" ");
		}
	}

	
//	for(i=1;i<6;i++)
//	{
//		if(A[i]==0)
//		{
//			printf("N");
//		}else
//		{
//			if(i==4)
//			{
//				printf("%0.1f",A[i]);
//			}elseif(i==2)
//			{
//				if()
//			}else
//			{
//				printf("%d",(int)(A[i]));
//			}
//		}
//		if(i!=5){
//			printf(" ");
//		}
//	}
	
	return 0;
}
