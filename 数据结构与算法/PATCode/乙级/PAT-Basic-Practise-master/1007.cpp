#include <stdio.h>
#include <math.h>
int isT(int m){
	int k;
	//Ö»ÐèÅÐ¶Ï2~¸ùºÅm 
	for(k=sqrt(m); k>1; k--){
		if(m%k == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int i, n, s=0;
	scanf("%d", &n);
	if(n <= 4){
		printf("0\n");
		return 0;
	}
	for(i=5; i<=n; i+=2){
		if( isT(i) && isT(i-2) )
			s++;
	}
	printf("%d\n", s);
	return 0;
}
