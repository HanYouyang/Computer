#include<stdio.h>

int main()
{
	int n;
	int a[3]={0};
	scanf("%d",&n);
	int b=0,s=0,i=0;
	for(i=0;n>0;i++){
		a[i]=n%10;
		n/=10;
	}
	if(a[2]>0){
		for(i=0;i<a[2];i++){
			printf("B");
		}
		
	}
	if(a[1]>0){
		for(i=0;i<a[1];i++){
			printf("S");
		}
		
	}
	for(i=1;i<=a[0];i++){
			printf("%d",i);
		}
	
	
	return 0;
}
