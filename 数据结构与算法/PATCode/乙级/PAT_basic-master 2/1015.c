#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int ID;
	int D;
	int C;
}list;
int cmp(const void *b,const void *a){//qsort的比较函数 
	list *c=(list*)a;
	list *d=(list*)b;
	int ret=0;
	if((c->C+c->D)!=(d->C+d->D))
	{
		ret=(c->C+c->D)-(d->C+d->D);
	}else
	{
		if(c->D!=d->D)
		{
			ret=c->D-d->D;
		}else
		{
			ret=d->ID-c->ID;
		}
	}
	return ret;
}

int main()
{
	int N,L,H,i;
	scanf("%d %d %d",&N,&L,&H);
	list *type1=(list*)malloc(N*sizeof(list));
	list *type2=(list*)malloc(N*sizeof(list));
	list *type3=(list*)malloc(N*sizeof(list));
	list *type4=(list*)malloc(N*sizeof(list));//四个结构数组分别存储四类学生 
	list input;
	int t1=0,t2=0,t3=0,t4=0;
	for(i=0;i<N;i++)
	{
		scanf("%d %d %d",&input.ID,&input.D,&input.C);
		if(input.D>=L&&input.C>=L)
		{
			if(input.D>=H&&input.C>=H)
			{
				type1[t1]=input;
				t1++;
			}else if(input.D>=H)
			{
				type2[t2]=input;
				t2++;
			}else if(input.D>=input.C)
			{
				type3[t3]=input;
				t3++;
			}else
			{
				type4[t4]=input;
				t4++;
			}
		}	
	}
	qsort(type1,t1,sizeof(list),cmp);
	qsort(type2,t2,sizeof(list),cmp);
	qsort(type3,t3,sizeof(list),cmp);
	qsort(type4,t4,sizeof(list),cmp);//对每类学生排序 
	printf("%d\n",t1+t2+t3+t4);
	for(i=0;i<t1;i++)
	{
		printf("%d %d %d\n",type1[i].ID,type1[i].D,type1[i].C);
	}
	for(i=0;i<t2;i++)
	{
		printf("%d %d %d\n",type2[i].ID,type2[i].D,type2[i].C);
	}
	for(i=0;i<t3;i++)
	{
		printf("%d %d %d\n",type3[i].ID,type3[i].D,type3[i].C);
	}
	for(i=0;i<t4;i++)
	{
		printf("%d %d %d\n",type4[i].ID,type4[i].D,type4[i].C);
	}
	return 0;
}
