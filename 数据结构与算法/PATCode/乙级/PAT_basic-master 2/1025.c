#include<stdio.h> 
#include<stdlib.h>
int main()
{
	int N,n,K,i,head,link;
	int value[100010]={0};/*link记录节点的地址，value[link]记录值，next[]记录下一个节点的地址*/
	int  next[100010]={0};
	int  list[100010]={0};/*list记录初始链表顺序，final记录反转后的链表顺序*/
	int final[100010]={0};
	scanf("%d %d %d",&head,&N,&K);
	for(i=0;i<N;i++)
	{
		scanf("%d",&link);/*这里link要单独输入，放在一起会出问题*/
		scanf("%d %d",&value[link],&next[link]);
	}
	
	n=0;
	while(head!=-1)
	{	
		list[n]=head;
		head=next[head];/*用list整理链表的顺序，以方便反转*/ 
		n++;/*n会不等于N，也就是说测试用例会给出没用的节点，这不是坑人吗*/
	}
	for(i=0;i<(n-n%K);i++)
	{
		final[i]=list[(i/K)*K+K-i%K-1];/*每K个节点反转，这个要好好找找规律*/
	} 
	for(i;i<n;i++)
	{
		final[i]=list[i];
	}
	
	for(i=0;i<n-1;i++)
	{
		printf("%05d %d %05d\n",final[i],value[final[i]],final[i+1]);
	}
	printf("%05d %d %d\n",final[n-1],value[final[n-1]],-1);
	
	return 0;
}
