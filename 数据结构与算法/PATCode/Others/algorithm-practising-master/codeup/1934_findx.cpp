#include <cstdio>

const int maxn=205;
int num[maxn];

int main()
{
	int n;
	int k;
  int x;
	while(scanf("%d", &n) != EOF){
  	for(int i = 0; i < n; i++){
  		scanf("%d", &num[i]);
  	}
  	scanf("%d",&x);
  	for(k = 0; k < n; k++){
  		if(num[k] == x){
  			printf("%d\n", k);
  			break;
  		}
  	}
  	if(k == n){
  		printf("-1\n");
  	}
	}
  return 0;
}
