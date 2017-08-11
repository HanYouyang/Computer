//2016年2月21日17时25分01秒
//2016年2月21日17时36分55秒
#include <cstdio>

const int maxn = 100010;

int main()
{
	int n, time = 0, from = 0, to;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &to);
		int temp;
		if(to > from){
			temp = 6 * (to - from) + 5;
		} else {
			temp = 4 * (from - to) + 5;
		}
		time += temp;
		from = to;
	}
	printf("%d\n", time);
	return 0;
}
