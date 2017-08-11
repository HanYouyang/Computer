#include<stdio.h>
#include<math.h>
int isPrime(int x);
int main()
{
	int M,N,i=1,l=1,cnt=0,count=1;
	int primes[10001]={0};
	scanf("%d %d",&M,&N);
	do
	{
		i++;
		if(isPrime(i))
		{
			primes[l]=i;
			l++;
			cnt++;
		}
	}while(cnt<N);
	for(i=M;i<N+1;i++)
	{
		printf("%d",primes[i]);
		cnt++;
		if(count%10==0){
			printf("\n",primes[i]);
			count++;
		}else if(count!=N-M+1)
		{		
			printf(" ");
			count++;
		}
		
		
	}

	return 0;
}

int isPrime(int x)
{
	int ret = 1;
	int i;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
		
		ret = 0;
		break;
		}
	}
	return ret;
}
