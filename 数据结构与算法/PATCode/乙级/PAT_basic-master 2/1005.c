#include<stdio.h>

int main()
{
	int k,i;
	int key[101]={0};
	int number[1000]={0};
/*	用key数组记录0-100是否被其他数覆盖，用number数组记录用户输入的数字。
	初始化key数组为0，用户输入过的所有序号置为1，完成猜想过程中出现过得数组序号置为0，最后key中为1的元素的编号及为未被覆盖的元素*/ 
	scanf("%d",&k);
	if(k<100)
	{
			for(i=0;i<k;i++)
		{
			scanf("%d",&number[i]);
			if(number[i]>1&&number[i]<=100)
			{
				key[number[i]]=1;
			}
			
		} 
		for(i=0;i<k;i++)
		{	int n;
			n=number[i];
			while(n!=1)
			{
				
				if(n%2)
				{
					n=(3*n+1)/2;
					if(n<=100){
						key[n]=0;
					}
					/*这里n可能会超过100，造成数组越界，这边要加一个判断*/ 
				}else
				{
					n/=2;
					if(n<=100){
						key[n]=0;
					}
					
				}
			}
		}
		int cnt=0;
		for(i=101;i>0;i--)
		{	
			if(key[i]==1)
			{	
				if(cnt>0){
					printf(" ");
				}
				printf("%d",i);
				cnt++;
			}
		}	
	}

	
	return 0;
}
