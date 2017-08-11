#include<stdio.h>  
int main()  
{
	long int a,b,c,x,i;  
    scanf("%ld",&x);
    for(i=0;i<x;i++){     
        scanf("%ld %ld %ld",&a,&b,&c);  
        if(a+b>c)
            printf("Case #%ld: true\n",i+1);   
        else  
            printf("Case #%ld: false\n",i+1);  
    }
}
