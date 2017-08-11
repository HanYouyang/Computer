#include<stdio.h>
#include<string.h>
int all_number(char *A,int n);/*校验前17位是否全为数字*/
int main()
{
	const int amount=17;
	int N,i,j,z,flag=0,sum=0;
	char id[19]={0};
	int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char M[12]={"10X98765432"};
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%s",id);
		sum=0;
		for(j=0;j<amount;j++)
		{
			sum+=(id[j]-'0')*a[j];/*加权求和*/
		}
		if(M[sum%11]!=id[17]||(all_number(id,amount)==0))
		{
			printf("%s\n",id);
			flag=1;/*是否输出all passed的标志*/
		}
		
	}
	if(flag==0)
	{
		printf("All passed");
	}
	
	
	return 0;
}
int all_number(char *A,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(A[i]>='0'&&A[i]<='9')
		{
			return 1;
		}else{
			return 0;
		}
	}
}
