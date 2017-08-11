#include <stdio.h>
int main()
{	
	int N;
	scanf("%d", &N);
	int k, num, score;
	int s[1001] = {0};
	for(int i = 1; i <= N; i++){
		scanf("%d-%d %d", &k, &num, &score);
        s[k] += score;
	}
	int max = 0;
    for (int i = 0; i < 1001; i++) {
        if (s[max] < s[i])
            max = i;
    }
    printf("%d %d", max, s[max]);
	return 0;
}
