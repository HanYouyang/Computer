#include <stdio.h>
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int i, s[n];
	for(i=0; i<n; i++){
		scanf("%d", &s[i]);
	}
	if(m % n){
		int k = n - (m % n);
		for(i=k; i<n; i++)
			printf("%d ", s[i]);
		for(i=0; i<k-1; i++)
			printf("%d ", s[i]);
		printf("%d\n", s[i]);
	} else {
		//�ƶ�n�������������鲻�� 
		for(i=0; i<n-1; i++)
			printf("%d ", s[i]);
		printf("%d\n", s[i]);
	}
	return 0;
}
