#include <stdio.h>
int main()
{
	int i, n;
	int j=0, p=0;
	scanf("%d", &n);
	int s[100001] = { 0 };
	
	for(i=0; i<n; i++){
		scanf("%d %d", &j, &p);
		s[j] += p;
	}
	
	int k=0;
	//遍历输出最大
	for(i=1; i<n+1; i++){
		if(s[i] > s[k])
			k = i;
	}
	printf("%d %d\n", k, s[k]);
	return 0;
}