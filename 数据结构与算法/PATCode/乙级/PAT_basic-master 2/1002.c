#include<stdio.h>
int main()
{
	char n[100]={0};
	int sum=0;
	scanf("%s",n);
	int i,number,mask=1;
	for(i=0;n[i]!=0;i++) {
		sum+=(int)n[i]-48;
	}
	int a=sum;
	while(a>9){
		a/=10;
		mask*=10;
		
	}

	do{
		number=sum/mask;
		sum%=mask;
		mask/=10;
		switch(number){
			case 0:printf("ling");break;
			case 1:printf("yi");break;
			case 2:printf("er");break;
			case 3:printf("san");break;
			case 4:printf("si");break;
			case 5:printf("wu");break;
			case 6:printf("liu");break;
			case 7:printf("qi");break;
			case 8:printf("ba");break;
			case 9:printf("jiu");break;
		}
		if(mask>0){
			printf(" ");
		}
	}while(mask>0);
//	switch(sum){
//			case 0:printf("ling");break;
//			case 1:printf("yi");break;
//			case 2:printf("er");break;
//			case 3:printf("san");break;
//			case 4:printf("si");break;
//			case 5:printf("wu");break;
//			case 6:printf("liu");break;
//			case 7:printf("qi");break;
//			case 8:printf("ba");break;
//			case 9:printf("jiu");break;
//	}
	return 0;
}
