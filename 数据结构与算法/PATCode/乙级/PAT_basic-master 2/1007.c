#include<stdio.h>
#include<math.h>

int isPrime(int a);
int main()
{
	int N,cnt;
	scanf("%d",&N);
	int a[10000]={0};
	int i,j,k;
	for(i=2;i<=N;i++){
		if(isPrime(i)){
			a[j]=i;
			j++;
		}
	}

	for(k=1;k<j;k++){
		if(a[k]-a[k-1]==2)cnt++;
	}
	printf("%d",cnt);
	
	
	return 0;
}

int isPrime(int a)
{
	int isPrime=1,i;
	for(i=2;i<=sqrt(a);i++)
	{
		if(a%i == 0){
			isPrime = 0;
			break;
		}
	}
	return isPrime;
}
