#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void*b);


int main()
{
	int n,p,i,j;
	scanf("%d %d",&n,&p);
	int *a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	int maxN=0;
	for(i=0;i<n;i++)
        for(j=i+maxN;j<n;j++)
        {
            if(a[i]*p<a[j])
                break;
            if(j-i+1>maxN)
                maxN =j-i+1;
        }
	printf("%d\n",maxN);
	return 0;
} 
cmp(const void *a,const void*b)
{
	return *(int*)a-*(int*)b;
}
