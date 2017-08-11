#include <stdio.h>
int main()
{
	int s[2000] = { 0 };
	int x, p, i=0;
	while(scanf("%d %d", &x, &p) == 2){
		if(x != 0 && p != 0){
			s[i] = x * p;
			s[i+1] = p - 1;
			i += 2;
		}
	}
	int j;
	for(j=0; j<i-2; j+=2)
		if(s[j+1] != 0)
			printf("%d %d ", s[j], s[j+1]);
	printf("%d %d\n", s[j], s[j+1]);
	
	return 0;
}
