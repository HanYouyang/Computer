#include<stdio.h>
int main()
{
	int factor,power;
	int flag=0;
//	是否输出空格的标记 
	char ch;
	do
	{
		scanf("%d %d",&factor,&power);
		ch=getchar();
//		每次从输入读取一个，直到读到回车，魂环结束 
		if(power==0)
		{
			if(flag==0){
				printf("0 0");/*输入为0 0的情况*/
			}
		}else
		{
			if(flag==0)
			{
				printf("%d %d",factor*power,power-1);
				flag=1;
			}else
			{
				printf(" %d %d",factor*power,power-1);
			}
			
		}
		
	}while(ch!='\n');
	return 0;
}
